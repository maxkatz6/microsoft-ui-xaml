﻿// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#pragma once

#include "ProgressBar.h"
#include "ProgressBarAutomationPeer.g.h"

class ProgressBarAutomationPeer :
    public ReferenceTracker<ProgressBarAutomationPeer, winrt::implementation::ProgressBarAutomationPeerT, winrt::IRangeValueProvider>
{

public:
    ProgressBarAutomationPeer(winrt::ProgressBar const& owner);

    // IAutomationPeerOverrides
    winrt::IInspectable GetPatternCore(winrt::PatternInterface const& patternInterface);
    hstring GetClassNameCore();
    winrt::AutomationControlType GetAutomationControlTypeCore();

    bool IsReadOnly() { return true; }
    double Value();
    double SmallChange();
    double LargeChange();
    double Minimum();
    double Maximum();
    void SetValue(double value);

private:
    com_ptr<ProgressBar> GetImpl();
};

