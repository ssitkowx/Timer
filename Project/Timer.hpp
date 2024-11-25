#pragma once 

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// INCLUDES /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
/////////////////////////// CLASSES/STRUCTURES ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

template <class DERIVED_TYPE>
class Timer
{
    friend DERIVED_TYPE;
    DERIVED_TYPE & derivedType = static_cast <DERIVED_TYPE &> (*this);

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

        Timer () = default;

        void Start    (void) { derivedType.Start    (); }
        void Stop     (void) { derivedType.Stop     (); }
        void StartIsr (void) { derivedType.StartIsr (); }
        void StopIsr  (void) { derivedType.StopIsr  (); }

        constexpr void Reset    (void)
        {
            Stop ();
            Start ();
        }

        constexpr void ResetIsr   (void)
        {
            StopIsr ();
            StartIsr ();
        }

        void     SetCounter (uint32_t v_counter) { derivedType.SetCounter (v_counter); }
        uint32_t GetCounter (void)               { return derivedType.GetCounter ();   }

    protected:
        void     init       (void)               { derivedType.init   (); }
        void     deInit     (void)               { derivedType.deInit (); }

    private:
        ~Timer () = default;
};

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// END OF FILE ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
