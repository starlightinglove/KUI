
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#ifndef SkTextBox_DEFINED
#define SkTextBox_DEFINED

#include "SkCanvas.h"

/** \class SkTextBox

    SkTextBox is a helper class for drawing 1 or more lines of text
    within a rectangle. The textbox is positioned and clipped by its Frame.
    The Margin rectangle controls where the text is drawn relative to
    the Frame. Line-breaks occur inside the Margin rectangle.

    Spacing is a linear equation used to compute the distance between lines
    of text. Spacing consists of two scalars: mul and add, and the spacing
    between lines is computed as: spacing = paint.getTextSize() * mul + add
*/
class SkTextBox {
public:
    SkTextBox();

    enum Mode {
        kOneLine_Mode,
        kLineBreak_Mode,

        kModeCount
    };
    Mode    getMode() const { return (Mode)fMode; }
    void    setMode(Mode);

    enum SpacingAlign {
        kStart_SpacingAlign,
        kCenter_SpacingAlign,
        kEnd_SpacingAlign,

        kSpacingAlignCount
    };
    SpacingAlign    getSpacingAlign() const { return (SpacingAlign)fSpacingAlign; }
    void            setSpacingAlign(SpacingAlign);

    void    getBox(SkRect*) const;
    void    setBox(const SkRect&);
    void    setBox(SkScalar left, SkScalar top, SkScalar right, SkScalar bottom);

    void    getSpacing(SkScalar* mul, SkScalar* add) const;
    void    setSpacing(SkScalar mul, SkScalar add);

    void    draw(SkCanvas*, const char text[], size_t len, const SkPaint&);

    void    setText(const char text[], size_t len, const SkPaint&);
    void    draw(SkCanvas*);
    int     countLines() const;
    SkScalar getTextHeight() const;
    SkScalar getTextWidth() const;  // add by evanlu 2013/11/02

private:
    SkRect      fBox;
    SkScalar    fSpacingMul, fSpacingAdd;
    uint8_t     fMode, fSpacingAlign;
    const char* fText;
    size_t      fLen;
    const SkPaint* fPaint;
};

class SkTextLineBreaker {
public:
    static int CountLines(const char text[], size_t len, const SkPaint&, SkScalar width);
};

#endif
