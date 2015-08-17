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

//[Headers] You can add your own extra header files here...
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
//[/Headers]

#include "MainComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainComponent::MainComponent (MyPluginProcessor* processor)
    : AudioProcessorEditor(processor), processor(processor)
{
    addAndMakeVisible (label13 = new Label ("new label",
                                            TRANS("4drX")));
    label13->setFont (Font (222.00f, Font::plain));
    label13->setJustificationType (Justification::centredLeft);
    label13->setEditable (false, false, false);
    label13->setColour (Label::backgroundColourId, Colour (0x00e4e4e4));
    label13->setColour (Label::textColourId, Colour (0x11f7f7f7));
    label13->setColour (TextEditor::textColourId, Colours::black);
    label13->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (channel2 = new Label (String::empty,
                                             TRANS("Output Channel:")));
    channel2->setFont (Font (19.00f, Font::plain));
    channel2->setJustificationType (Justification::centredLeft);
    channel2->setEditable (false, false, false);
    channel2->setColour (Label::textColourId, Colours::white);
    channel2->setColour (TextEditor::textColourId, Colours::black);
    channel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (channel4 = new Label (String::empty,
                                             TRANS("Send Bank Change:")));
    channel4->setFont (Font (19.00f, Font::plain));
    channel4->setJustificationType (Justification::centredLeft);
    channel4->setEditable (false, false, false);
    channel4->setColour (Label::textColourId, Colours::white);
    channel4->setColour (TextEditor::textColourId, Colours::black);
    channel4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (channel6 = new Label (String::empty,
                                             TRANS("Send Program Change:")));
    channel6->setFont (Font (19.00f, Font::plain));
    channel6->setJustificationType (Justification::centredLeft);
    channel6->setEditable (false, false, false);
    channel6->setColour (Label::textColourId, Colours::white);
    channel6->setColour (TextEditor::textColourId, Colours::black);
    channel6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("The 3 Mod Keys Start At:")));
    label->setFont (Font (19.00f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colours::white);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (firstModKeyComboBox = new ComboBox ("firstModKeyComboBox"));
    firstModKeyComboBox->setEditableText (false);
    firstModKeyComboBox->setJustificationType (Justification::centredLeft);
    firstModKeyComboBox->setTextWhenNothingSelected (String::empty);
    firstModKeyComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    firstModKeyComboBox->addItem (TRANS("C#2"), 1);
    firstModKeyComboBox->addListener (this);

    addAndMakeVisible (channel7 = new Label (String::empty,
                                             TRANS("Input Channel:")));
    channel7->setFont (Font (19.00f, Font::plain));
    channel7->setJustificationType (Justification::centredLeft);
    channel7->setEditable (false, false, false);
    channel7->setColour (Label::textColourId, Colours::white);
    channel7->setColour (TextEditor::textColourId, Colours::black);
    channel7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (masterChannelComboBox = new ComboBox ("masterChannelComboBox"));
    masterChannelComboBox->setEditableText (false);
    masterChannelComboBox->setJustificationType (Justification::centredLeft);
    masterChannelComboBox->setTextWhenNothingSelected (String::empty);
    masterChannelComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    masterChannelComboBox->addItem (TRANS("1"), 1);
    masterChannelComboBox->addItem (TRANS("2"), 2);
    masterChannelComboBox->addItem (TRANS("3"), 3);
    masterChannelComboBox->addItem (TRANS("4"), 4);
    masterChannelComboBox->addItem (TRANS("5"), 5);
    masterChannelComboBox->addItem (TRANS("6"), 6);
    masterChannelComboBox->addItem (TRANS("7"), 7);
    masterChannelComboBox->addItem (TRANS("8"), 8);
    masterChannelComboBox->addItem (TRANS("9"), 9);
    masterChannelComboBox->addItem (TRANS("10"), 10);
    masterChannelComboBox->addItem (TRANS("11"), 11);
    masterChannelComboBox->addItem (TRANS("12"), 12);
    masterChannelComboBox->addItem (TRANS("13"), 13);
    masterChannelComboBox->addItem (TRANS("14"), 14);
    masterChannelComboBox->addItem (TRANS("15"), 15);
    masterChannelComboBox->addItem (TRANS("16"), 16);
    masterChannelComboBox->addListener (this);

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("3rd Mod Key+(1-16)")));
    label2->setFont (Font (12.00f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (Label::textColourId, Colours::white);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("2nd Mod Key+(1-64)")));
    label3->setFont (Font (12.00f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (Label::textColourId, Colours::white);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label4 = new Label ("new label",
                                           TRANS("1st Mod Key+(1-64)")));
    label4->setFont (Font (12.00f, Font::plain));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (Label::textColourId, Colours::white);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label5 = new Label ("new label",
                                           TRANS("1st+3rd Mod Keys+(65-128)")));
    label5->setFont (Font (12.00f, Font::plain));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (Label::textColourId, Colours::white);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (channel = new Label (String::empty,
                                            TRANS("16")));
    channel->setFont (Font (46.00f, Font::plain));
    channel->setJustificationType (Justification::centredLeft);
    channel->setEditable (false, false, false);
    channel->setColour (Label::textColourId, Colours::white);
    channel->setColour (TextEditor::textColourId, Colours::black);
    channel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (program = new Label (String::empty,
                                            TRANS("128")));
    program->setFont (Font (46.00f, Font::plain));
    program->setJustificationType (Justification::centredLeft);
    program->setEditable (false, false, false);
    program->setColour (Label::textColourId, Colours::white);
    program->setColour (TextEditor::textColourId, Colours::black);
    program->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (hyperlinkButton = new HyperlinkButton (TRANS("click here to donate"),
                                                              URL ("http://www.4drx.com/midikeyswitcher/donate")));
    hyperlinkButton->setTooltip (TRANS("http://www.4drx.com/midikeyswitcher/donate"));
    hyperlinkButton->setButtonText (TRANS("click here to donate"));
    hyperlinkButton->setColour (HyperlinkButton::textColourId, Colour (0xccffffff));

    addAndMakeVisible (label6 = new Label ("new label",
                                           TRANS("If you are enjoying it and would like to hear about new features, show me some love:")));
    label6->setFont (Font (17.50f, Font::plain));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (Label::textColourId, Colours::white);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label7 = new Label ("new label",
                                           TRANS("MidiKeySwitcher\n")));
    label7->setFont (Font (17.00f, Font::plain));
    label7->setJustificationType (Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (Label::textColourId, Colours::black);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (hyperlinkButton2 = new HyperlinkButton (TRANS("More"),
                                                               URL ("http://www.4drx.com/midikeyswitcher")));
    hyperlinkButton2->setTooltip (TRANS("http://www.4drx.com/midikeyswitcher"));
    hyperlinkButton2->setButtonText (TRANS("More"));
    hyperlinkButton2->setColour (HyperlinkButton::textColourId, Colour (0xff050505));

    addAndMakeVisible (label8 = new Label ("new label",
                                           TRANS("1")));
    label8->setFont (Font (15.00f, Font::bold));
    label8->setJustificationType (Justification::centredLeft);
    label8->setEditable (false, false, false);
    label8->setColour (Label::textColourId, Colour (0xffe61c1c));
    label8->setColour (TextEditor::textColourId, Colours::black);
    label8->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label9 = new Label ("new label",
                                           TRANS("2")));
    label9->setFont (Font (15.00f, Font::bold));
    label9->setJustificationType (Justification::centredLeft);
    label9->setEditable (false, false, false);
    label9->setColour (Label::textColourId, Colour (0xffe61c1c));
    label9->setColour (TextEditor::textColourId, Colours::black);
    label9->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label10 = new Label ("new label",
                                            TRANS("3\n")));
    label10->setFont (Font (15.00f, Font::bold));
    label10->setJustificationType (Justification::centredLeft);
    label10->setEditable (false, false, false);
    label10->setColour (Label::textColourId, Colour (0xffe61c1c));
    label10->setColour (TextEditor::textColourId, Colours::black);
    label10->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label11 = new Label ("new label",
                                            TRANS("4")));
    label11->setFont (Font (15.00f, Font::bold));
    label11->setJustificationType (Justification::centredLeft);
    label11->setEditable (false, false, false);
    label11->setColour (Label::textColourId, Colour (0xffe61c1c));
    label11->setColour (TextEditor::textColourId, Colours::black);
    label11->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label12 = new Label ("new label",
                                            TRANS("...")));
    label12->setFont (Font (15.00f, Font::bold));
    label12->setJustificationType (Justification::centredLeft);
    label12->setEditable (false, false, false);
    label12->setColour (Label::textColourId, Colour (0xffe61c1c));
    label12->setColour (TextEditor::textColourId, Colours::black);
    label12->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (bank = new Label (String::empty,
                                         TRANS("16")));
    bank->setFont (Font (46.00f, Font::plain));
    bank->setJustificationType (Justification::centredLeft);
    bank->setEditable (false, false, false);
    bank->setColour (Label::textColourId, Colours::white);
    bank->setColour (TextEditor::textColourId, Colours::black);
    bank->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    int octave=3-5; //octave for Middle C: 3
    String label;
    for (int i=0;i<128;i++){
      switch (i%12){
        case 0: label="C"; break;
        case 1: label="C#"; break;
        case 2: label="D"; break;
        case 3: label="D#"; break;
        case 4: label="E"; break;
        case 5: label="F"; break;
        case 6: label="F#"; break;
        case 7: label="G"; break;
        case 8: label="G#"; break;
        case 9: label="A"; break;
        case 10: label="A#"; break;
        case 11: label="B"; break;
        default: break;
      }
      label+=(String)(octave+i/12);
      firstModKeyComboBox->addItem (label,i+1);
    }

    processor->updateUi(true,true);

    timerCallback();
    //[/UserPreSize]

    setSize (700, 490);


    //[Constructor] You can add your own custom stuff here..
    startTimer (50);
    //[/Constructor]
}

MainComponent::~MainComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label13 = nullptr;
    channel2 = nullptr;
    channel4 = nullptr;
    channel6 = nullptr;
    label = nullptr;
    firstModKeyComboBox = nullptr;
    channel7 = nullptr;
    masterChannelComboBox = nullptr;
    label2 = nullptr;
    label3 = nullptr;
    label4 = nullptr;
    label5 = nullptr;
    channel = nullptr;
    program = nullptr;
    hyperlinkButton = nullptr;
    label6 = nullptr;
    label7 = nullptr;
    hyperlinkButton2 = nullptr;
    label8 = nullptr;
    label9 = nullptr;
    label10 = nullptr;
    label11 = nullptr;
    label12 = nullptr;
    bank = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::black);

    g.setColour (Colour (0xff2aa551));
    g.fillPath (internalPath1);

    g.setColour (Colour (0xff0e0f0d));
    g.fillEllipse (631.0f, 382.0f, 43.0f, 36.0f);

    g.setColour (Colour (0xff9a0000));
    g.fillRect (572, 453, 77, 49);

    g.setColour (Colour (0xff17305a));
    g.fillPath (internalPath2);

    g.setColour (Colour (0xff191916));
    g.fillRect (633, 417, 12, 23);

    g.setColour (Colour (0xff3e3e3e));
    g.fillPath (internalPath3);

    g.setColour (Colour (0xff3e3e3e));
    g.fillRect (288, 112, 96, 21);

    g.setColour (Colour (0xff3e3e3e));
    g.fillPath (internalPath4);

    g.setColour (Colour (0xff3e3e3e));
    g.fillRect (280, 180, 109, 21);

    g.setColour (Colour (0xff3e3e3e));
    g.fillPath (internalPath5);

    g.setColour (Colour (0xff3e3e3e));
    g.fillRect (236, 249, 151, 21);

    g.setColour (Colour (0xffa0a52a));
    g.fillPath (internalPath6);

    g.setColour (Colour (0xff3e3e3e));
    g.fillPath (internalPath7);

    g.setColour (Colour (0xff3e3e3e));
    g.fillRect (237, 278, 150, 21);

    g.setColour (Colour (0xff0e0f0d));
    g.fillEllipse (606.0f, 352.0f, 52.0f, 49.0f);

    g.setColour (Colour (0xff0e0f0d));
    g.fillEllipse (565.0f, 318.0f, 77.0f, 60.0f);

    g.setColour (Colours::white);
    g.fillRect (260, 22, 20, 60);

    g.setColour (Colours::white);
    g.fillRect (282, 22, 20, 60);

    g.setColour (Colour (0xff232323));
    g.fillRect (274, 22, 14, 38);

    g.setColour (Colours::white);
    g.fillRect (304, 22, 20, 60);

    g.setColour (Colour (0xff06ff00));
    g.fillRect (266, 70, 1, 183);

    g.setColour (Colour (0xff00abff));
    g.fillRect (275, 70, 1, 21);

    g.setColour (Colour (0xff00abff));
    g.fillRect (287, 70, 1, 20);

    g.setColour (Colour (0xff00abff));
    g.fillRect (276, 90, 12, 1);

    g.setColour (Colour (0xffa500ff));
    g.fillRect (295, 70, 1, 45);

    g.setColour (Colour (0xff00abff));
    g.fillRect (275, 91, 1, 190);

    g.setColour (Colour (0xfff9ff00));
    g.fillRect (284, 49, 1, 136);

    g.setColour (Colours::white);
    g.fillRect (326, 22, 20, 60);

    g.setColour (Colour (0xff232323));
    g.fillRect (318, 22, 14, 38);

    g.setColour (Colours::white);
    g.fillRect (304, 22, 20, 60);

    g.setColour (Colours::white);
    g.fillRect (326, 22, 20, 60);

    g.setColour (Colour (0xff232323));
    g.fillRect (318, 22, 14, 38);

    g.setColour (Colours::white);
    g.fillRect (347, 22, 20, 60);

    g.setColour (Colour (0xff232323));
    g.fillRect (339, 22, 14, 38);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainComponent::resized()
{
    label13->setBounds (111, 182, 510, 477);
    channel2->setBounds (455, 102, 140, 41);
    channel4->setBounds (432, 173, 166, 41);
    channel6->setBounds (412, 252, 189, 41);
    label->setBounds (2, 48, 191, 24);
    firstModKeyComboBox->setBounds (194, 45, 55, 26);
    channel7->setBounds (65, 102, 130, 41);
    masterChannelComboBox->setBounds (195, 110, 55, 26);
    label2->setBounds (285, 111, 114, 24);
    label3->setBounds (277, 179, 117, 24);
    label4->setBounds (254, 248, 114, 24);
    label5->setBounds (253, 276, 161, 24);
    channel->setBounds (604, 100, 58, 41);
    program->setBounds (604, 251, 87, 41);
    hyperlinkButton->setBounds (541, 364, 147, 24);
    label6->setBounds (10, 352, 536, 46);
    label7->setBounds (574, 10, 133, 24);
    hyperlinkButton2->setBounds (518, 465, 186, 25);
    label8->setBounds (304, 59, 22, 15);
    label9->setBounds (316, 44, 22, 15);
    label10->setBounds (326, 59, 22, 15);
    label11->setBounds (337, 44, 22, 15);
    label12->setBounds (347, 59, 21, 15);
    bank->setBounds (604, 170, 58, 41);
    internalPath1.clear();
    internalPath1.startNewSubPath (494.0f, 541.0f);
    internalPath1.lineTo (544.0f, 530.0f);
    internalPath1.lineTo (103.0f, 476.0f);
    internalPath1.lineTo (29.0f, 440.0f);
    internalPath1.lineTo (static_cast<float> (-9), 453.0f);
    internalPath1.lineTo (static_cast<float> (-57), 481.0f);
    internalPath1.lineTo (static_cast<float> (-103), 519.0f);
    internalPath1.closeSubPath();

    internalPath2.clear();
    internalPath2.startNewSubPath (610.0f, 411.0f);
    internalPath2.lineTo (662.0f, 455.0f);
    internalPath2.lineTo (559.0f, 457.0f);
    internalPath2.closeSubPath();

    internalPath3.clear();
    internalPath3.startNewSubPath (409.0f, 123.0f);
    internalPath3.lineTo (382.0f, 144.0f);
    internalPath3.lineTo (381.0f, 102.0f);
    internalPath3.closeSubPath();

    internalPath4.clear();
    internalPath4.startNewSubPath (412.0f, 190.0f);
    internalPath4.lineTo (385.0f, 211.0f);
    internalPath4.lineTo (384.0f, 169.0f);
    internalPath4.closeSubPath();

    internalPath5.clear();
    internalPath5.startNewSubPath (411.0f, 257.0f);
    internalPath5.lineTo (384.0f, 278.0f);
    internalPath5.lineTo (383.0f, 236.0f);
    internalPath5.closeSubPath();

    internalPath6.clear();
    internalPath6.startNewSubPath (521.0f, 13.0f);
    internalPath6.lineTo (563.0f, 30.0f);
    internalPath6.lineTo (557.0f, 74.0f);
    internalPath6.lineTo (606.0f, 51.0f);
    internalPath6.lineTo (634.0f, 81.0f);
    internalPath6.lineTo (667.0f, 53.0f);
    internalPath6.lineTo (706.0f, 69.0f);
    internalPath6.lineTo (711.0f, 29.0f);
    internalPath6.lineTo (761.0f, 87.0f);
    internalPath6.lineTo (739.0f, 12.0f);
    internalPath6.lineTo (770.0f, static_cast<float> (-4));
    internalPath6.lineTo (728.0f, static_cast<float> (-5));
    internalPath6.lineTo (706.0f, static_cast<float> (-6));
    internalPath6.lineTo (663.0f, static_cast<float> (-58));
    internalPath6.lineTo (621.0f, static_cast<float> (-12));
    internalPath6.lineTo (571.0f, static_cast<float> (-18));
    internalPath6.closeSubPath();

    internalPath7.clear();
    internalPath7.startNewSubPath (411.0f, 289.0f);
    internalPath7.lineTo (384.0f, 310.0f);
    internalPath7.lineTo (383.0f, 268.0f);
    internalPath7.closeSubPath();

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == firstModKeyComboBox)
    {
        //[UserComboBoxCode_firstModKeyComboBox] -- add your combo box handling code here..
        if (firstModKeyComboBox->getSelectedId()>0){
          processor->getInt8Param(MyPluginProcessor::firstModKeyIndex)->updateProcessorAndHostFromUi((uint8)(firstModKeyComboBox->getSelectedId()-1));
        }
        //[/UserComboBoxCode_firstModKeyComboBox]
    }
    else if (comboBoxThatHasChanged == masterChannelComboBox)
    {
        //[UserComboBoxCode_masterChannelComboBox] -- add your combo box handling code here..
        if (masterChannelComboBox->getSelectedId()>0){
          processor->getInt8Param(MyPluginProcessor::masterChannelIndex)->updateProcessorAndHostFromUi((uint8)(masterChannelComboBox->getSelectedId()));
        }
        //[/UserComboBoxCode_masterChannelComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MainComponent::timerCallback(){
    Int8Param *intParam=processor->getInt8Param(MyPluginProcessor::forceMidiChannelIndex);
    if (channel && intParam->updateUiRequested()){
      channel->setText(String(intParam->uiGet()), dontSendNotification);
    }
    if (intParam->uiGet()>0){
      Uint8Param *bankParam=processor->getUint8ParamArray(MyPluginProcessor::banksIndex)->getUint8Param(intParam->uiGet()-1);
      if (bank && bankParam->updateUiRequested()){
        bank->setText(String(bankParam->uiGet()), dontSendNotification);
      }
      Uint8Param *programParam=processor->getUint8ParamArray(MyPluginProcessor::programsIndex)->getUint8Param(intParam->uiGet()-1);
      if (program && programParam->updateUiRequested()){
        program->setText(String(programParam->uiGet()), dontSendNotification);
      }
    }
    Int8Param* const firstModKeyParam=processor->getInt8Param(MyPluginProcessor::firstModKeyIndex);
    if (firstModKeyComboBox && firstModKeyParam->updateUiRequested()){
      firstModKeyComboBox->setSelectedId(firstModKeyParam->uiGet()+1,dontSendNotification);
    }
    Int8Param* const masterChannelParam=processor->getInt8Param(MyPluginProcessor::masterChannelIndex);
    if (masterChannelComboBox && masterChannelParam->updateUiRequested()){
      masterChannelComboBox->setSelectedId(masterChannelParam->uiGet(),dontSendNotification);
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainComponent" componentName=""
                 parentClasses="public AudioProcessorEditor, public Timer" constructorParams="MyPluginProcessor* processor"
                 variableInitialisers="AudioProcessorEditor(processor), processor(processor)"
                 snapPixels="8" snapActive="0" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="700" initialHeight="490">
  <BACKGROUND backgroundColour="ff000000">
    <PATH pos="0 0 100 100" fill="solid: ff2aa551" hasStroke="0" nonZeroWinding="1">s 494 541 l 544 530 l 103 476 l 29 440 l -9 453 l -57 481 l -103 519 x</PATH>
    <ELLIPSE pos="631 382 43 36" fill="solid: ff0e0f0d" hasStroke="0"/>
    <RECT pos="572 453 77 49" fill="solid: ff9a0000" hasStroke="0"/>
    <PATH pos="0 0 100 100" fill="solid: ff17305a" hasStroke="0" nonZeroWinding="1">s 610 411 l 662 455 l 559 457 x</PATH>
    <RECT pos="633 417 12 23" fill="solid: ff191916" hasStroke="0"/>
    <PATH pos="0 0 100 100" fill="solid: ff3e3e3e" hasStroke="0" nonZeroWinding="1">s 409 123 l 382 144 l 381 102 x</PATH>
    <RECT pos="288 112 96 21" fill="solid: ff3e3e3e" hasStroke="0"/>
    <PATH pos="0 0 100 100" fill="solid: ff3e3e3e" hasStroke="0" nonZeroWinding="1">s 412 190 l 385 211 l 384 169 x</PATH>
    <RECT pos="280 180 109 21" fill="solid: ff3e3e3e" hasStroke="0"/>
    <PATH pos="0 0 100 100" fill="solid: ff3e3e3e" hasStroke="0" nonZeroWinding="1">s 411 257 l 384 278 l 383 236 x</PATH>
    <RECT pos="236 249 151 21" fill="solid: ff3e3e3e" hasStroke="0"/>
    <PATH pos="0 0 100 100" fill="solid: ffa0a52a" hasStroke="0" nonZeroWinding="1">s 521 13 l 563 30 l 557 74 l 606 51 l 634 81 l 667 53 l 706 69 l 711 29 l 761 87 l 739 12 l 770 -4 l 728 -5 l 706 -6 l 663 -58 l 621 -12 l 571 -18 x</PATH>
    <PATH pos="0 0 100 100" fill="solid: ff3e3e3e" hasStroke="0" nonZeroWinding="1">s 411 289 l 384 310 l 383 268 x</PATH>
    <RECT pos="237 278 150 21" fill="solid: ff3e3e3e" hasStroke="0"/>
    <ELLIPSE pos="606 352 52 49" fill="solid: ff0e0f0d" hasStroke="0"/>
    <ELLIPSE pos="565 318 77 60" fill="solid: ff0e0f0d" hasStroke="0"/>
    <RECT pos="260 22 20 60" fill="solid: ffffffff" hasStroke="0"/>
    <RECT pos="282 22 20 60" fill="solid: ffffffff" hasStroke="0"/>
    <RECT pos="274 22 14 38" fill="solid: ff232323" hasStroke="0"/>
    <RECT pos="304 22 20 60" fill="solid: ffffffff" hasStroke="0"/>
    <RECT pos="266 70 1 183" fill="solid: ff06ff00" hasStroke="0"/>
    <RECT pos="275 70 1 21" fill="solid: ff00abff" hasStroke="0"/>
    <RECT pos="287 70 1 20" fill="solid: ff00abff" hasStroke="0"/>
    <RECT pos="276 90 12 1" fill="solid: ff00abff" hasStroke="0"/>
    <RECT pos="295 70 1 45" fill="solid: ffa500ff" hasStroke="0"/>
    <RECT pos="275 91 1 190" fill="solid: ff00abff" hasStroke="0"/>
    <RECT pos="284 49 1 136" fill="solid: fff9ff00" hasStroke="0"/>
    <RECT pos="326 22 20 60" fill="solid: ffffffff" hasStroke="0"/>
    <RECT pos="318 22 14 38" fill="solid: ff232323" hasStroke="0"/>
    <RECT pos="304 22 20 60" fill="solid: ffffffff" hasStroke="0"/>
    <RECT pos="326 22 20 60" fill="solid: ffffffff" hasStroke="0"/>
    <RECT pos="318 22 14 38" fill="solid: ff232323" hasStroke="0"/>
    <RECT pos="347 22 20 60" fill="solid: ffffffff" hasStroke="0"/>
    <RECT pos="339 22 14 38" fill="solid: ff232323" hasStroke="0"/>
  </BACKGROUND>
  <LABEL name="new label" id="40675a0de0db5712" memberName="label13" virtualName=""
         explicitFocusOrder="0" pos="111 182 510 477" bkgCol="e4e4e4"
         textCol="11f7f7f7" edTextCol="ff000000" edBkgCol="0" labelText="4drX"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="222" bold="0" italic="0" justification="33"/>
  <LABEL name="" id="c3e8d9afda39bf20" memberName="channel2" virtualName=""
         explicitFocusOrder="0" pos="455 102 140 41" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Output Channel:"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="19" bold="0" italic="0" justification="33"/>
  <LABEL name="" id="86fe71a8a218cd95" memberName="channel4" virtualName=""
         explicitFocusOrder="0" pos="432 173 166 41" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Send Bank Change:"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="19" bold="0" italic="0" justification="33"/>
  <LABEL name="" id="394fe354e530c884" memberName="channel6" virtualName=""
         explicitFocusOrder="0" pos="412 252 189 41" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Send Program Change:"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="19" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="7cff342a130f03f7" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="2 48 191 24" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="The 3 Mod Keys Start At:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="19" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="firstModKeyComboBox" id="ed187231c2cc1bed" memberName="firstModKeyComboBox"
            virtualName="" explicitFocusOrder="0" pos="194 45 55 26" editable="0"
            layout="33" items="C#2" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="" id="28e1c9bf469abd4c" memberName="channel7" virtualName=""
         explicitFocusOrder="0" pos="65 102 130 41" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Input Channel:"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="19" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="masterChannelComboBox" id="502bacd1ae3fcb89" memberName="masterChannelComboBox"
            virtualName="" explicitFocusOrder="0" pos="195 110 55 26" editable="0"
            layout="33" items="1&#10;2&#10;3&#10;4&#10;5&#10;6&#10;7&#10;8&#10;9&#10;10&#10;11&#10;12&#10;13&#10;14&#10;15&#10;16"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="59870ea54f2b1065" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="285 111 114 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="3rd Mod Key+(1-16)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="b603e3a18bdc4385" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="277 179 117 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="2nd Mod Key+(1-64)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="7720dc8d89f42acb" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="254 248 114 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="1st Mod Key+(1-64)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="5251fd0f9d3039f2" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="253 276 161 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="1st+3rd Mod Keys+(65-128)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="0" italic="0" justification="33"/>
  <LABEL name="" id="1d41bfcc397457ab" memberName="channel" virtualName=""
         explicitFocusOrder="0" pos="604 100 58 41" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="16" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="46" bold="0" italic="0" justification="33"/>
  <LABEL name="" id="84db38ee3aa3cc9b" memberName="program" virtualName=""
         explicitFocusOrder="0" pos="604 251 87 41" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="128" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="46" bold="0" italic="0" justification="33"/>
  <HYPERLINKBUTTON name="new hyperlink" id="7a35e24b9e903fd1" memberName="hyperlinkButton"
                   virtualName="" explicitFocusOrder="0" pos="541 364 147 24" tooltip="http://www.4drx.com/midikeyswitcher/donate"
                   textCol="ccffffff" buttonText="click here to donate" connectedEdges="0"
                   needsCallback="0" radioGroupId="0" url="http://www.4drx.com/midikeyswitcher/donate"/>
  <LABEL name="new label" id="9f15b92c7eaf8ec6" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="10 352 536 46" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="If you are enjoying it and would like to hear about new features, show me some love:"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="17.5" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="22a43e35527931a1" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="574 10 133 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="MidiKeySwitcher&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="17" bold="0" italic="0" justification="33"/>
  <HYPERLINKBUTTON name="new hyperlink" id="6ac60ee220258e4a" memberName="hyperlinkButton2"
                   virtualName="" explicitFocusOrder="0" pos="518 465 186 25" tooltip="http://www.4drx.com/midikeyswitcher"
                   textCol="ff050505" buttonText="More" connectedEdges="0" needsCallback="0"
                   radioGroupId="0" url="http://www.4drx.com/midikeyswitcher"/>
  <LABEL name="new label" id="d074e92e799a3a67" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="304 59 22 15" textCol="ffe61c1c"
         edTextCol="ff000000" edBkgCol="0" labelText="1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="new label" id="5051d2afff9aecaa" memberName="label9" virtualName=""
         explicitFocusOrder="0" pos="316 44 22 15" textCol="ffe61c1c"
         edTextCol="ff000000" edBkgCol="0" labelText="2" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="new label" id="724db495cb7d1eb3" memberName="label10" virtualName=""
         explicitFocusOrder="0" pos="326 59 22 15" textCol="ffe61c1c"
         edTextCol="ff000000" edBkgCol="0" labelText="3&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="new label" id="426b52f2d597e3a" memberName="label11" virtualName=""
         explicitFocusOrder="0" pos="337 44 22 15" textCol="ffe61c1c"
         edTextCol="ff000000" edBkgCol="0" labelText="4" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="new label" id="afdaaabcebafaa" memberName="label12" virtualName=""
         explicitFocusOrder="0" pos="347 59 21 15" textCol="ffe61c1c"
         edTextCol="ff000000" edBkgCol="0" labelText="..." editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="" id="488263b8fa885fdd" memberName="bank" virtualName=""
         explicitFocusOrder="0" pos="604 170 58 41" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="16" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="46" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
