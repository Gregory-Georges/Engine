#ifndef DEBUG_HPP_INCLUDED
#define DEBUG_HPP_INCLUDED



//Is already defined by the project
//#define ENGINE_DEBUG



#ifdef ENGINE_DEBUG

#else
    #error No support for release mode yet
#endif



#endif // DEBUG_HPP_INCLUDED
