#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"


class NewProjectAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                        public juce::Slider::Listener
{
public:
    NewProjectAudioProcessorEditor (NewProjectAudioProcessor&);
    ~NewProjectAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged(juce::Slider *slider) override;

private:
   NewProjectAudioProcessor& audioProcessor;

    juce::Slider gainSlider; 
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NewProjectAudioProcessorEditor)
};
