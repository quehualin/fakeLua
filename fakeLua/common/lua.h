// common/lua.h
#ifndef lua_h
#define lua_h

static int POINTER_SIZE = sizeof(void*); //根据指针所占字节数，判断是32位还是64位

#if POINTER_SIZE >= 8 //64位系统
#define LUA_INTEGER long    //8个字节
#define LUA_NUMBER double   //8个字节
#else //32位系统
#define LUA_INTEGER int     //4个字节
#define LUA_NUMBER float    //4个字节
#endif

// basic object type
#define LUA_TNUMBER 1           // number
#define LUA_TLIGHTUSERDATA 2    // light user data
#define LUA_TBOOLEAN 3          // boolean
#define LUA_TSTRING 4           // string
#define LUA_TNIL 5              // nil
#define LUA_TTABLE 6            // table
#define LUA_TFUNCTION 7         // function
#define LUA_TTHREAD 8           // thread
#define LUA_TNONE 9             // none

/*
** Type for memory-allocation functions
*/
typedef void * (*lua_Alloc) (void *ud, void *ptr, size_t osize, size_t nsize);

#endif