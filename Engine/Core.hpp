#ifndef CORE_HPP_INCLUDED
#define CORE_HPP_INCLUDED



//Bit operator macro
#define BIT(x) (1 << x)



//Assertions and error detection
#ifdef ENGINE_DEBUG
    #define ENGINE_ENABLE_ASSERTS
#endif // ENGINE_DEBUG

#ifdef ENGINE_ENABLE_ASSERTS
    #define ENGINE_ASSERT(x, y){if(!(x)){ ENGINE_ERROR("Assertion failed : " << y); throw(std::exception()); }}
    #define ENGINE_CORE_ASSERT(x, y){if(!(x)){ ENGINE_ERROR("Assertion failed : " << y); throw(std::exception()); }}
#else
    #define ENGINE_ASSERT(x, y)
    #define ENGINE_CORE_ASSERT(x, y)
#endif



#endif // CORE_HPP_INCLUDED
