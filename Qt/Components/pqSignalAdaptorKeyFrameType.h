/*=========================================================================

   Program:   ParaView
   Module:    pqSignalAdaptorKeyFrameType.h

   Copyright (c) 2005,2006 Sandia Corporation, Kitware Inc.
   All rights reserved.

   ParaView is a free software; you can redistribute it and/or modify it
   under the terms of the ParaView license version 1.1. 

   See License_v1.1.txt for the full ParaView license.
   A copy of this license can be obtained by contacting
   Kitware Inc.
   28 Corporate Drive
   Clifton Park, NY 12065
   USA

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=========================================================================*/
#ifndef __pqSignalAdaptorKeyFrameType_h
#define __pqSignalAdaptorKeyFrameType_h

#include "pqComponentsExport.h"
#include "pqSignalAdaptors.h"

class vtkSMProxy;
class QLabel;

// pqSignalAdaptorKeyFrameType is adaptor for the "Type" property of the 
// vtkSMCompositeKeyFrameProxy. For certain types of keyframes, 
// we have additional properties that must be exposed in the GUI,
// this class manages that. 
// Use this to connect a QComboBox with type listing 
// to the Type property on the proxy.
class PQCOMPONENTS_EXPORT pqSignalAdaptorKeyFrameType : 
  public pqSignalAdaptorComboBox
{
  Q_OBJECT;
public:
  // Constructor. 
  // \c combo is the combo-box that chooses the type, while frame is
  // the frame in which this adaptor can put additional widgets, if needed.
  // \c valueLabel is the label that is used for the keyframe value,
  // since based on the type  the value label may change.
  // Note that this class will toggle the visibility of this frame as needed.
  pqSignalAdaptorKeyFrameType(QComboBox* combo, QLabel* valueLabel, QWidget* frame);
  virtual ~pqSignalAdaptorKeyFrameType();

  // \c keyframe is the proxy for the key frame. It typically is
  // a vtkSMCompositeKeyFrameProxy or subclass.
  // This is needed to setup the links with the other properties.
  void setKeyFrameProxy(vtkSMProxy* keyframe);
  vtkSMProxy* getKeyFrameProxy() const;

private slots:
  // Called when the combo-box changes
  void onTypeChanged();

private:
  pqSignalAdaptorKeyFrameType(const pqSignalAdaptorKeyFrameType&); // Not implemented.
  void operator=(const pqSignalAdaptorKeyFrameType&); // Not implemented.

  class pqInternals;
  pqInternals* Internals;

};

#endif

