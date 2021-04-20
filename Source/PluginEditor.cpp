#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
   setSize (200, 400);
    
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 80, 25);
    gainSlider.setRange(0.0, 1.0);
    gainSlider.setValue(0.5);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    
    
}

void NewProjectAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getLocalBounds());
}

void NewProjectAudioProcessorEditor::sliderValueChanged(juce::Slider *slider){
    
    if (slider == &gainSlider){
        audioProcessor.rawVolume = gainSlider.getValue();
    }
}

