#ifndef KEYCODES_HPP_INCLUDED
#define KEYCODES_HPP_INCLUDED



namespace Engine
{

    using KeyCode = uint16_t;

    namespace Key
    {
        enum : KeyCode
        {
            // From glfw3.h
            Space,
            Apostrophe,
            Comma,
            Minus,
            Period,
            Slash,


            D1,
            D2,
            D3,
            D4,
            D5,
            D6,
            D7,
            D8,
            D9,

            Semicolon,
            Equal,

            A,
            B,
            C,
            D,
            E,
            F,
            G,
            H,
            I,
            J,
            K,
            L,
            M,
            N,
            O,
            P,
            Q,
            R,
            S,
            T,
            U,
            V,
            W,
            X,
            Y,
            Z,

            LeftBracket,
            Backslash,
            RightBracket,
            GraveAccent,

            World1,
            World2,

            /* Function keys */
            Escape,
            Enter,
            Tab,
            Backspace,
            Insert,
            Delete,
            Right,
            Left,
            Down,
            Up,
            PageUp,
            PageDown,
            Home,
            End,
            CapsLock,
            ScrollLock,
            NumLock,
            PrintScreen,
            Pause,
            F1,
            F2,
            F3,
            F4,
            F5,
            F6,
            F7,
            F8,
            F9,
            F10,
            F11,
            F12,
            F13,
            F14,
            F15,
            F16,
            F17,
            F18,
            F19,
            F20,
            F21,
            F22,
            F23,
            F24,
            F25,

            /* Keypad */
            KP0,
            KP1,
            KP2,
            KP3,
            KP4,
            KP5,
            KP6,
            KP7,
            KP8,
            KP9,
            KPDecimal,
            KPDivide,
            KPMultiply,
            KPSubtract,
            KPAdd,
            KPEnter,
            KPEqual,

            LeftShift,
            LeftControl,
            LeftAlt,
            LeftSuper,
            RightShift,
            RightControl,
            RightAlt,
            RightSuper,
            Menu,
        };
    }



    using MouseCode = uint16_t;

    namespace Mouse
    {
        enum : MouseCode
        {
            // From glfw3.h
            Button0,
            Button1,
            Button2,
            Button3,
            Button4,
            Button5,
            Button6,
            Button7,

            ButtonLast,
            ButtonLeft,
            ButtonRight,
            ButtonMiddle,
        };
    }
}



#endif // KEYCODES_HPP_INCLUDED
