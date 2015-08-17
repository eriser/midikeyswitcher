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
  forceMidiChannel(0),
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
            if (midiMessage.isNoteOn()){
              forceMidiChannelMode=true;
            } else {
              forceMidiChannelMode=false;
            }
          } else if (midiMessage.getNoteNumber()==firstModKey){            
            if (midiMessage.isNoteOn()){
              setMidiProgramMode=true;              
            } else {
              setMidiProgramMode=false;
            }
          } else if (midiMessage.getNoteNumber()==firstModKey+1){
            if (midiMessage.isNoteOn()){
              setMidiBankMode=true;
            } else {
              setMidiBankMode=false;
            }          
          } else if (forceMidiChannelMode && !setMidiBankMode && !setMidiProgramMode && midiMessage.getNoteNumber()>=firstModKey+3 && midiMessage.getNoteNumber()<=firstModKey+3+18){
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
            getUint8ParamArray(banksIndex)->getUint8Param(forceMidiChannel-1)->updateUi();
            getUint8ParamArray(programsIndex)->getUint8Param(forceMidiChannel-1)->updateUi();

          } else if (forceMidiChannel>0 && !forceMidiChannelMode && setMidiBankMode && !setMidiProgramMode && midiMessage.getNoteNumber()>=firstModKey+3 && midiMessage.getNoteNumber()<=firstModKey+66){
            int bank=midiMessage.getNoteNumber()-firstModKey-3;
            banks[forceMidiChannel-1]=(uint8)(bank+1);
            getUint8ParamArray(banksIndex)->getUint8Param(forceMidiChannel-1)->updateUi();
            midiMessages.addEvent(MidiMessage::controllerEvent(forceMidiChannel,0,bank),0);
            midiMessages.addEvent(MidiMessage::controllerEvent(forceMidiChannel,32,bank),0);

          } else if (forceMidiChannel>0 && !setMidiBankMode && setMidiProgramMode && midiMessage.getNoteNumber()>=firstModKey+3 && midiMessage.getNoteNumber()<=firstModKey+66){
            int program;
            if (!forceMidiChannelMode)
              program=midiMessage.getNoteNumber()-firstModKey-3;
            else 
              program=64+midiMessage.getNoteNumber()-firstModKey-3;
            programs[forceMidiChannel-1]=(uint8)(program+1);
            getUint8ParamArray(programsIndex)->getUint8Param(forceMidiChannel-1)->updateUi();
            midiMessages.addEvent(MidiMessage::programChange(forceMidiChannel,program),0);

          } else {
            if (forceMidiChannel!=0) 
              midiMessage.setChannel(forceMidiChannel);

            midiMessage.setNoteNumber(jlimit(0,128,midiMessage.getNoteNumber()+noteOffset));              

            midiMessages.addEvent(midiMessage,sampleNumber);
          }
        } else {//channel 1 Midi but not NoteOnOff
          if (forceMidiChannel!=0) 
              midiMessage.setChannel(forceMidiChannel);              

          midiMessages.addEvent(midiMessage,sampleNumber);
        }
      } else {//channel !=masterChannel
        if (forceMidi10 && midiMessage.getChannel()==10){
          midiMessage.setChannel(1);
          if (midiMessage.isNoteOnOrOff()){
            midiMessage.setNoteNumber(jlimit(0,128,midiMessage.getNoteNumber()+noteOffset));
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
