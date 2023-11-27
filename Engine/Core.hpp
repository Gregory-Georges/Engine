#ifndef CORE_HPP_INCLUDED
#define CORE_HPP_INCLUDED



//Bit operator macro
#define BIT(x) (1 << x)



//Assertions and error detection
#ifdef ENGINE_DEBUG
        #define ENGINE_ENABLE_ASSERTS
#endif // ENGINE_DEBUG

#ifdef ENGINE_ENABLE_ASSERTS
    #define ENGINE_ASSERT(x, y){if(!(x)){ ENGINE_ERROR(std::string("Assertion failed : ") + y); throw(std::exception()); }}
    #define ENGINE_CORE_ASSERT(x, y){if(!(x)){ ENGINE_ERROR(std::string("Assertion failed : ") + y); throw(std::exception()); }}
#else
    #define ENGINE_ASSERT(x, y)
    #define ENGINE_CORE_ASSERT(x, y)
#endif



//Refs and scopes
namespace Engine
{
    template <typename T>
    using Scope = std::unique_ptr<T>;

    template <typename T>
    using Ref = std::shared_ptr<T>;
}



#endif // CORE_HPP_INCLUDED
