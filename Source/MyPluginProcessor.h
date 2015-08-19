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

#ifndef __PLUGINPROCESSOR_H_526ED7A9__
#define __PLUGINPROCESSOR_H_526ED7A9__

#include "../JuceLibraryCode/JuceHeader.h"

class MyPluginProcessor  : public PluginProcessor{
  
public:
    MyPluginProcessor();
    ~MyPluginProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock);
    
    void releaseResources();
    
    void processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages);
    
    double getTailLengthSeconds(void) const{
      return 0;
    } 

    void reset();

    //==============================================================================
    bool hasEditor() const                  { return true; }
    AudioProcessorEditor* createEditor();          
    
    bool forceMidi10;
    int8 noteOffset;
    int8 forceMidiChannel;
    bool forceMidiChannelMode;
    bool setMidiBankMode;
    bool setMidiProgramMode;

    int8 banks[16];
    int8 programs[16];

    int8 masterChannel;
    int8 firstModKey;
      
    enum Params{
      forceMidiChannelIndex=0,
      masterChannelIndex,
      firstModKeyIndex
    };

    enum ParamGroups{
      banksIndex=0,
      programsIndex
    };
      
    void initParameters(){        
      //Params
      addInt8Param(forceMidiChannelIndex,"channel",true,SAVE,&forceMidiChannel,1,16);
      addInt8Param(masterChannelIndex,"masterChannelIndex",false,SAVE,&masterChannel,1,16);
      addInt8Param(firstModKeyIndex,"firstModKey",false,SAVE,&firstModKey,0,127);
      //ParamGroups
      addInt8ParamArray(banksIndex,"banks",false,SAVE,banks,nullptr,16,0,127);
      addInt8ParamArray(programsIndex,"programs",false,SAVE,programs,nullptr,16,0,127);
    }     

private:
    //==============================================================================

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MyPluginProcessor);
};

#endif  // __PLUGINPROCESSOR_H_526ED7A9__
