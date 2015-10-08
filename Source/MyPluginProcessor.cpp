/*
==============================================================================

This file is part of the MidiKeySwitcher plugin.
Copyright 2015 by 4drX

Permission is granted to use this software under the terms of the
GPL v2 (or any later version).

Details of this license can be found at: http://www.gnu.org/licenses
------------------------------------------------------------------------------

In order to build this Software you'll need the JUCE library(http://juce.com)
and the PluginParameters module(https://www.github.com/4drX/pluginparameters),
which have separate licenses.

==============================================================================
*/

#include "MyPluginProcessor.h"
#include "MainComponent.h"

MyPluginProcessor::MyPluginProcessor():
  forceMidi10(false),
  noteOffset(0),
  forceMidiChannel(1),
  forceMidiChannelMode(false),
  setMidiBankMode(false),
  setMidiProgramMode(false),
  masterChannel(1),
  firstModKey(21)
{
    for (int i=0;i<16;i++){
      banks[i]=0;
      programs[i]=0;
    }

    initAllParameters();
}

MyPluginProcessor::~MyPluginProcessor(){  
}

void MyPluginProcessor::prepareToPlay (double /*sampleRate*/, int /*samplesPerBlock*/){
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void MyPluginProcessor::releaseResources(){
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void MyPluginProcessor::reset(){
    // Use this method as the place to clear any delay lines, buffers, etc, as it
    // means there's been a break in the audio's continuity.
    //reset the phase
}

void MyPluginProcessor::processBlock (AudioSampleBuffer& /*buffer*/, MidiBuffer& midiMessages){
    //force midiChannel
    MidiBuffer midiMessagesTmp(midiMessages);
    midiMessages.clear();
    MidiBuffer::Iterator nextMidiMessage(midiMessagesTmp);
    MidiMessage midiMessage;	
    int sampleNumber;

    nextMidiMessage.setNextSamplePosition(0);      
    while (nextMidiMessage.getNextEvent(midiMessage, sampleNumber)){
      if (midiMessage.getChannel()==masterChannel){
        if (midiMessage.isNoteOnOrOff()){
          if (midiMessage.getNoteNumber()==firstModKey+2){
            if (midiMessage.isNoteOn() && midiMessage.getVelocity()>0){
              forceMidiChannelMode=true;
              if (setMidiBankMode && setMidiProgramMode){
                for (int c=forceMidiChannel;c<=forceMidiChannel;c++){
                  midiMessages.addEvent(MidiMessage::controllerEvent(c,0,banks[c-1]),0);
                  midiMessages.addEvent(MidiMessage::controllerEvent(c,32,banks[c-1]),0);
                  midiMessages.addEvent(MidiMessage::programChange(c,programs[c-1]),0);
                }
              } else if (setMidiBankMode && programs[forceMidiChannel-1]<127){
                getInt8ParamArray(banksIndex)->getInt8Param(forceMidiChannel-1)->updateUi();
                midiMessages.addEvent(MidiMessage::controllerEvent(forceMidiChannel,0,banks[forceMidiChannel-1]),0);
                midiMessages.addEvent(MidiMessage::controllerEvent(forceMidiChannel,32,banks[forceMidiChannel-1]),0);

                programs[forceMidiChannel-1]++;
                getInt8ParamArray(programsIndex)->getInt8Param(forceMidiChannel-1)->updateUi();
                midiMessages.addEvent(MidiMessage::programChange(forceMidiChannel,programs[forceMidiChannel-1]),0);
              }
            } else {
              forceMidiChannelMode=false;
            }
          } else if (midiMessage.getNoteNumber()==firstModKey){            
            if (midiMessage.isNoteOn() && midiMessage.getVelocity()>0){
              setMidiProgramMode=true;
              if (setMidiBankMode && forceMidiChannelMode){
                for (int c=forceMidiChannel;c<=forceMidiChannel;c++){
                  midiMessages.addEvent(MidiMessage::controllerEvent(c,0,banks[c-1]),0);
                  midiMessages.addEvent(MidiMessage::controllerEvent(c,32,banks[c-1]),0);
                  midiMessages.addEvent(MidiMessage::programChange(c,programs[c-1]),0);
                }
              } else if (setMidiBankMode && programs[forceMidiChannel-1]>0){                
                midiMessages.addEvent(MidiMessage::controllerEvent(forceMidiChannel,0,banks[forceMidiChannel-1]),0);
                midiMessages.addEvent(MidiMessage::controllerEvent(forceMidiChannel,32,banks[forceMidiChannel-1]),0);

                programs[forceMidiChannel-1]--;
                getInt8ParamArray(programsIndex)->getInt8Param(forceMidiChannel-1)->updateUi();
                midiMessages.addEvent(MidiMessage::programChange(forceMidiChannel,programs[forceMidiChannel-1]),0);
              }
            } else {
              setMidiProgramMode=false;
            }
          } else if (midiMessage.getNoteNumber()==firstModKey+1){
            if (midiMessage.isNoteOn() && midiMessage.getVelocity()>0){
              setMidiBankMode=true;
              if (forceMidiChannelMode && setMidiProgramMode){
                for (int c=forceMidiChannel;c<=forceMidiChannel;c++){
                  midiMessages.addEvent(MidiMessage::controllerEvent(c,0,banks[c-1]),0);
                  midiMessages.addEvent(MidiMessage::controllerEvent(c,32,banks[c-1]),0);
                  midiMessages.addEvent(MidiMessage::programChange(c,programs[c-1]),0);
                }
              } else if (setMidiProgramMode && programs[forceMidiChannel-1]>0){                
                midiMessages.addEvent(MidiMessage::controllerEvent(forceMidiChannel,0,banks[forceMidiChannel-1]),0);
                midiMessages.addEvent(MidiMessage::controllerEvent(forceMidiChannel,32,banks[forceMidiChannel-1]),0);

                programs[forceMidiChannel-1]--;
                getInt8ParamArray(programsIndex)->getInt8Param(forceMidiChannel-1)->updateUi();
                midiMessages.addEvent(MidiMessage::programChange(forceMidiChannel,programs[forceMidiChannel-1]),0);
              } else if (forceMidiChannelMode && programs[forceMidiChannel-1]<127){
                midiMessages.addEvent(MidiMessage::controllerEvent(forceMidiChannel,0,banks[forceMidiChannel-1]),0);
                midiMessages.addEvent(MidiMessage::controllerEvent(forceMidiChannel,32,banks[forceMidiChannel-1]),0);

                programs[forceMidiChannel-1]++;
                getInt8ParamArray(programsIndex)->getInt8Param(forceMidiChannel-1)->updateUi();
                midiMessages.addEvent(MidiMessage::programChange(forceMidiChannel,programs[forceMidiChannel-1]),0);
              }
            } else {
              setMidiBankMode=false;
            }          
          } else if (forceMidiChannelMode && !setMidiBankMode && !setMidiProgramMode && midiMessage.getNoteNumber()>=firstModKey+3 && midiMessage.getNoteNumber()<=firstModKey+3+18){
            if (midiMessage.isNoteOn() && midiMessage.getVelocity()>0){
              forceMidiChannel=(int8)(midiMessage.getNoteNumber()-firstModKey-2);
              switch(forceMidiChannel){
                case 17: {
                  forceMidi10=false;
                  forceMidiChannel=1;
                  noteOffset=48;
                  break;
                } 
                case 18: {
                  forceMidi10=true;
                  forceMidiChannel=1;
                  noteOffset=0;
                  break;
                } 
                case 19: {
                  forceMidi10=true;
                  forceMidiChannel=1;
                  noteOffset=48;
                  break;
                }
                default: {
                  forceMidi10=false;
                  noteOffset=0;
                  break;
                }
              }
              getInt8Param(forceMidiChannelIndex)->updateUi();
              getInt8ParamArray(banksIndex)->getInt8Param(forceMidiChannel-1)->updateUi();
              getInt8ParamArray(programsIndex)->getInt8Param(forceMidiChannel-1)->updateUi();
            }

          } else if (!forceMidiChannelMode && setMidiBankMode && !setMidiProgramMode && midiMessage.getNoteNumber()>=firstModKey+3 && midiMessage.getNoteNumber()<=firstModKey+18){
            if (midiMessage.isNoteOn() && midiMessage.getVelocity()>0){
              int8 bank=midiMessage.getNoteNumber()-firstModKey-3;
              banks[forceMidiChannel-1]=bank;
              getInt8ParamArray(banksIndex)->getInt8Param(forceMidiChannel-1)->updateUi();
              midiMessages.addEvent(MidiMessage::controllerEvent(forceMidiChannel,0,bank),0);
              midiMessages.addEvent(MidiMessage::controllerEvent(forceMidiChannel,32,bank),0);

              programs[forceMidiChannel-1]=0;
              getInt8ParamArray(programsIndex)->getInt8Param(forceMidiChannel-1)->updateUi();
              midiMessages.addEvent(MidiMessage::programChange(forceMidiChannel,0),0);
            }

          } else if (!setMidiBankMode && setMidiProgramMode && midiMessage.getNoteNumber()>=firstModKey+3 && midiMessage.getNoteNumber()<=firstModKey+66){
            if (midiMessage.isNoteOn() && midiMessage.getVelocity()>0){
              int program;
              if (!forceMidiChannelMode)
                program=midiMessage.getNoteNumber()-firstModKey-3;
              else 
                program=64+midiMessage.getNoteNumber()-firstModKey-3;
            
              midiMessages.addEvent(MidiMessage::controllerEvent(forceMidiChannel,0,banks[forceMidiChannel-1]),0);
              midiMessages.addEvent(MidiMessage::controllerEvent(forceMidiChannel,32,banks[forceMidiChannel-1]),0);

              programs[forceMidiChannel-1]=program;
              getInt8ParamArray(programsIndex)->getInt8Param(forceMidiChannel-1)->updateUi();
              midiMessages.addEvent(MidiMessage::programChange(forceMidiChannel,program),0);
            }

          } else {
            midiMessage.setChannel(forceMidiChannel);

            midiMessage.setNoteNumber(jlimit(0,127,midiMessage.getNoteNumber()+noteOffset));              

            midiMessages.addEvent(midiMessage,sampleNumber);
          }
        } else {//channel==masterChannel but not NoteOnOff
          midiMessage.setChannel(forceMidiChannel);              

          midiMessages.addEvent(midiMessage,sampleNumber);
        }
      } else {//channel!=masterChannel
        if (forceMidi10 && midiMessage.getChannel()==10){
          midiMessage.setChannel(1);
          if (midiMessage.isNoteOnOrOff()){
            midiMessage.setNoteNumber(jlimit(0,127,midiMessage.getNoteNumber()+noteOffset));
          }
        }
        midiMessages.addEvent(midiMessage,sampleNumber);
      }
    }
}

//------------------------------------------------------------------------------
// Hook up the User Interface.
AudioProcessorEditor* MyPluginProcessor::createEditor(){
    return new MainComponent (this);
}

//------------------------------------------------------------------------------
// This creates new instances of the plugin.
AudioProcessor* JUCE_CALLTYPE createPluginFilter(){
    return new MyPluginProcessor();
}
