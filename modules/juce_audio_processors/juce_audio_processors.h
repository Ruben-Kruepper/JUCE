/*
  ==============================================================================

   This file is part of the JUCE library.
   Copyright (c) 2015 - ROLI Ltd.

   Permission is granted to use this software under the terms of either:
   a) the GPL v2 (or any later version)
   b) the Affero GPL v3

   Details of these licenses can be found at: www.gnu.org/licenses

   JUCE is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
   A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

   ------------------------------------------------------------------------------

   To release a closed-source product which uses JUCE, commercial licenses are
   available: visit www.juce.com for more information.

  ==============================================================================
*/

/*******************************************************************************
 The block below describes the properties of this module, and is read by
 the Projucer to automatically generate project code that uses it.
 For details about the syntax and how to create or use a module, see the
 JUCE Module Format.txt file.


 BEGIN_JUCE_MODULE_DECLARATION

  ID:               juce_audio_processors
  vendor:           juce
  version:          4.3.1
  name:             JUCE audio processor classes
  description:      Classes for loading and playing VST, AU, or internally-generated audio processors.
  website:          http://www.juce.com/juce
  license:          GPL/Commercial

  dependencies:     juce_gui_extra, juce_audio_basics
  OSXFrameworks:    CoreAudio CoreMIDI AudioToolbox
  iOSFrameworks:    AudioToolbox

 END_JUCE_MODULE_DECLARATION

*******************************************************************************/


#pragma once
#define JUCE_AUDIO_PROCESSORS_H_INCLUDED

#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_audio_basics/juce_audio_basics.h>

#if JucePlugin_EnhancedAudioSuite
#if ! JUCE_MODULE_AVAILABLE_juce_audio_formats
#error To compile random access support plug-in formats, you need to add the juce_audio_formats module!
#endif
#include <juce_audio_formats/juce_audio_formats.h>
#endif

//==============================================================================
/** Config: JUCE_PLUGINHOST_VST
    Enables the VST audio plugin hosting classes.

    @see VSTPluginFormat, VST3PluginFormat, AudioPluginFormat, AudioPluginFormatManager, JUCE_PLUGINHOST_AU, JUCE_PLUGINHOST_VST3
*/
#ifndef JUCE_PLUGINHOST_VST
 #define JUCE_PLUGINHOST_VST 0
#endif

/** Config: JUCE_PLUGINHOST_VST3
    Enables the VST3 audio plugin hosting classes. This requires the Steinberg VST3 SDK to be
    installed on your machine.

    @see VSTPluginFormat, VST3PluginFormat, AudioPluginFormat, AudioPluginFormatManager, JUCE_PLUGINHOST_VST, JUCE_PLUGINHOST_AU
*/
#ifndef JUCE_PLUGINHOST_VST3
 #define JUCE_PLUGINHOST_VST3 0
#endif

/** Config: JUCE_PLUGINHOST_AU
    Enables the AudioUnit plugin hosting classes. This is Mac-only, of course.

    @see AudioUnitPluginFormat, AudioPluginFormat, AudioPluginFormatManager, JUCE_PLUGINHOST_VST, JUCE_PLUGINHOST_VST3
*/
#ifndef JUCE_PLUGINHOST_AU
 #define JUCE_PLUGINHOST_AU 0
#endif

#if ! (JUCE_PLUGINHOST_AU || JUCE_PLUGINHOST_VST || JUCE_PLUGINHOST_VST3)
// #error "You need to set either the JUCE_PLUGINHOST_AU and/or JUCE_PLUGINHOST_VST and/or JUCE_PLUGINHOST_VST3 flags if you're using this module!"
#endif

#if ! (defined (JUCE_SUPPORT_CARBON) || JUCE_64BIT || JUCE_IOS)
 #define JUCE_SUPPORT_CARBON 1
#endif

#ifndef JUCE_SUPPORT_LEGACY_AUDIOPROCESSOR
 #define JUCE_SUPPORT_LEGACY_AUDIOPROCESSOR 1
#endif

//==============================================================================
//==============================================================================
namespace juce
{

class AudioProcessor;
#include "processors/juce_AudioProcessorEditor.h"
#include "processors/juce_AudioProcessorListener.h"
#include "processors/juce_AudioProcessorParameter.h"
#include "processors/juce_AudioProcessor.h"
#include "processors/juce_PluginDescription.h"
#include "processors/juce_AudioPluginInstance.h"
#include "processors/juce_AudioProcessorGraph.h"
#include "processors/juce_GenericAudioProcessorEditor.h"
#include "format/juce_AudioPluginFormat.h"
#include "format/juce_AudioPluginFormatManager.h"
#include "scanning/juce_KnownPluginList.h"
#include "format_types/juce_AudioUnitPluginFormat.h"
#include "format_types/juce_LADSPAPluginFormat.h"
#include "format_types/juce_VSTMidiEventList.h"
#include "format_types/juce_VSTPluginFormat.h"
#include "format_types/juce_VST3PluginFormat.h"
#include "scanning/juce_PluginDirectoryScanner.h"
#include "scanning/juce_PluginListComponent.h"
#include "utilities/juce_AudioProcessorParameterWithID.h"
#include "utilities/juce_AudioParameterFloat.h"
#include "utilities/juce_AudioParameterInt.h"
#include "utilities/juce_AudioParameterBool.h"
#include "utilities/juce_AudioParameterChoice.h"
#include "utilities/juce_AudioProcessorValueTreeState.h"

}
