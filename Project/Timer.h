#pragma once 

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// INCLUDES /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
/////////////////////////// CLASSES/STRUCTURES ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

class Timer
{
    public:
        enum class ETimer : uint8_t
        {
            e0,
            e1,
            e7,
            e14,
            e16,
            e17,
        };

        Timer          () = default;
        virtual ~Timer () = default;

        virtual void     Start      (void)               = 0;
        virtual void     Stop       (void)               = 0;
        virtual void     StartIsr   (void)               = 0;
        virtual void     StopIsr    (void)               = 0;
        virtual void     Reset      (void)               = 0;
        virtual void     ResetIsr   (void)               = 0;

        virtual void     SetCounter (uint32_t v_counter) = 0;
        virtual uint32_t GetCounter (void)               = 0;

    protected:
        virtual void     init       (void)               = 0;
        virtual void     deInit     (void)               = 0;
};

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// END OF FILE ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
