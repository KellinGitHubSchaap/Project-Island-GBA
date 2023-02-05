#include "../include/BPS/key_inputs.hpp"

u16 __current_key = 0;
u16 __previous_key = 0;

u32 GetKey(u32 key)
{
    return (__current_key & __previous_key) & key;
}

u32 GetKeyDown(u32 key)
{
	return (__current_key & ~__previous_key) & key;
}

u32 GetKeyUp(u32 key)
{
	return (~__current_key & __previous_key) & key;
}