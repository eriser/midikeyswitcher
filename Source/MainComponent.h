/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_9002020A4DD09B20__
#define __JUCE_HEADER_9002020A4DD09B20__

//[Headers]     -- You can add your own extra header files here --
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
#include "../JuceLibraryCode/JuceHeader.h"
#include "MyPluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainComponent  : public AudioProcessorEditor,
                       public Timer,
                       public ComboBoxListener
{
public:
    //==============================================================================
    MainComponent (MyPluginProcessor* processor);
    ~MainComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    // handy wrapper method to avoid having to cast the filter to a MyPluginProcessor
	  // every time we need it..
	  MyPluginProcessor * processor;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> label13;
    ScopedPointer<Label> channel2;
    ScopedPointer<Label> channel4;
    ScopedPointer<Label> channel6;
    ScopedPointer<Label> label;
    ScopedPointer<ComboBox> firstModKeyComboBox;
    ScopedPointer<Label> channel7;
    ScopedPointer<ComboBox> masterChannelComboBox;
    ScopedPointer<Label> label2;
    ScopedPointer<Label> label3;
    ScopedPointer<Label> label4;
    ScopedPointer<Label> label5;
    ScopedPointer<Label> channel;
    ScopedPointer<Label> program;
    ScopedPointer<HyperlinkButton> hyperlinkButton;
    ScopedPointer<Label> label6;
    ScopedPointer<Label> label7;
    ScopedPointer<HyperlinkButton> hyperlinkButton2;
    ScopedPointer<Label> label8;
    ScopedPointer<Label> label9;
    ScopedPointer<Label> label10;
    ScopedPointer<Label> label11;
    ScopedPointer<Label> label12;
    ScopedPointer<Label> bank;
    Path internalPath1;
    Path internalPath2;
    Path internalPath3;
    Path internalPath4;
    Path internalPath5;
    Path internalPath6;
    Path internalPath7;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_9002020A4DD09B20__
