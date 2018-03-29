/*
    Copyright (C) <2018>  <Kasi Reddy>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "KInputCtrl.hpp"

std::string KInputPath = R"(C:\Users\Kasi\Desktop\KInput\bin\Release\KInput.dll)";

KInputCtrl::KInputCtrl(DWORD PID) : Injector(PID)
{
    this->Load(KInputPath);
}

bool KInputCtrl::FocusEvent(std::int32_t ID)
{
    struct FocusEvent
    {
        std::int32_t ID;
    };
    FocusEvent Event;
    Event.ID = ID;
    return this->CallExport(KInputPath, "KInput_FocusEvent", &Event, sizeof(Event));
}

bool KInputCtrl::KeyEvent(std::int32_t ID, std::int64_t When, std::int32_t Modifiers, std::int32_t KeyCode,
                          std::uint16_t KeyChar, std::int32_t KeyLocation)
{
    struct KeyEvent
    {
        std::int32_t ID;
        std::int64_t When;
        std::int32_t Modifiers;
        std::int32_t KeyCode;
        std::uint16_t KeyChar;
        std::int32_t KeyLocation;
    };
    KeyEvent Event;
    Event.ID = ID;
    Event.When = When;
    Event.Modifiers = Modifiers;
    Event.KeyCode = KeyCode;
    Event.KeyChar = KeyChar;
    Event.KeyLocation = KeyLocation;
    return this->CallExport(KInputPath, "KInput_KeyEvent", &Event, sizeof(Event));
}

bool KInputCtrl::MouseEvent(std::int32_t ID, std::int64_t When, std::int32_t Modifiers, std::int32_t X,
                            std::int32_t Y, std::int32_t ClickCount, bool PopupTrigger, std::int32_t Button)
{
    struct MouseEvent
    {
        std::int32_t ID;
        std::int64_t When;
        std::int32_t Modifiers;
        std::int32_t X;
        std::int32_t Y;
        std::int32_t ClickCount;
        bool PopupTrigger;
        std::int32_t Button;
    };
    MouseEvent Event;
    Event.ID = ID;
    Event.When = When;
    Event.Modifiers = Modifiers;
    Event.X = X;
    Event.Y = Y;
    Event.ClickCount = ClickCount;
    Event.PopupTrigger = PopupTrigger;
    Event.Button = Button;
    return this->CallExport(KInputPath, "KInput_MouseEvent", &Event, sizeof(Event));
}

bool KInputCtrl::MouseWheelEvent(std::int32_t ID, std::int64_t When, std::int32_t Modifiers, std::int32_t X,
                                 std::int32_t Y, std::int32_t ClickCount, bool PopupTrigger, std::int32_t ScrollType,
                                 std::int32_t ScrollAmount, std::int32_t WheelRotation)
{
    struct MouseWheelEvent
    {
        std::int32_t ID;
        std::int64_t When;
        std::int32_t Modifiers;
        std::int32_t X;
        std::int32_t Y;
        std::int32_t ClickCount;
        bool PopupTrigger;
        std::int32_t ScrollType;
        std::int32_t ScrollAmount;
        std::int32_t WheelRotation;
    };
    MouseWheelEvent Event;
    Event.ID = ID;
    Event.When = When;
    Event.Modifiers = Modifiers;
    Event.X = X;
    Event.Y = Y;
    Event.ClickCount = ClickCount;
    Event.PopupTrigger = PopupTrigger;
    Event.ScrollType = ScrollType;
    Event.ScrollAmount = ScrollAmount;
    Event.WheelRotation = WheelRotation;
    return this->CallExport(KInputPath, "KInput_MouseWheelEvent", &Event, sizeof(Event));
}

KInputCtrl::~KInputCtrl()
{
    this->Free(KInputPath);
}
