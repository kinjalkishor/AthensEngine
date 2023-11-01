#pragma once

// Good Speed & memory open addressing unordered_dense map.
//-https://github.com/martinus/unordered_dense
// robin_hood::unordered_node_map with bulk allocator
//-https://github.com/martinus/robin-hood-hashing
// Ordered map. Use with std::vector as backing container. See ordered_map_v below.
//-https://github.com/Tessil/ordered-map
// Insert & erase is very fast, Search performance is ok but not stellar. Memory usage is ok-ish.
// Though hopscotch_map has the main advantage of being able to cope much better with a high load factor (> 0.6). 
// Tessil hash maps have minor difference in interface from std::unordered_map also.
//-https://github.com/Tessil/hopscotch-map
// Memory usage is very good (Uses less memory), a bit higher than greg7mdp/sparsepp, copying is a bit faster than non-parallel flat_hash_map. 
// Search is a bit slower than the non-parallel variant. It’s still fast though.
// The parallel hash maps are preferred when you have a few hash maps that will store a very large number of values. 
// The non-parallel hash maps are preferred if you have a large number of hash maps, each storing a relatively small number of values.
//-https://github.com/greg7mdp/parallel-hashmap
// emhash8 node's memory is continuous like std::vector, very fast iteration speed, search & insert is very fast and low memory usage.
//-https://github.com/ktprime/emhash

// plf::colony - An unordered bucket-like data container providing fast iteration/insertion/erasure while maintaining 
// pointer/iterator validity to non-erased elements.
// plf::list - On average 333% faster insertion, 81% faster erasure and 16% faster iteration than std::list.
// erasure and 16% faster iteration.
// plf::stack, plf::queue - Better performance than standard library 
// plf::rand - A replacement for rand()/srand() that's ~700% faster with (typically) better statistical distribution. 
// An adaptation of PCG with fallback to xorshift for C++98/03.
//-https://plflib.org/

// ankerl::unordered_dense::map
#include "ds/martinus/unordered_dense.h"
// robin_hood::unordered_node_map (uses bulk allocator)
//#include "ds/martinus/robin_hood.h"
// Use std::unordered_map for large elements as it does one node allocation for each element.

namespace ankerl {}
namespace ank = ankerl;

//template <class Key,
//			class T,
//			class Hash = ankerl::unordered_dense::hash<Key>,
//			class KeyEqual = std::equal_to<Key>,
//			class Bucket = ankerl::unordered_dense::bucket_type::standard>
//using ank_pmr_map =
//    ankerl::unordered_dense::detail::table<Key, T, Hash, KeyEqual, std::pmr::polymorphic_allocator<std::pair<Key, T>>, Bucket, false>;


// for wyhash
//#include "ds/martinus/unordered_dense.h"
// Use std::vector as ValueTypeContainer backing container instead of std::deque
    //#include "ds/tessil/ordered_map.h"
    //namespace tsl {
    //template <class Key, 
    //		  class T, 
    //		  class Hash = ankerl::unordered_dense::ANKERL_UNORDERED_DENSE_NAMESPACE::hash<Key>,
    //          class KeyEqual = std::equal_to<Key>,
    //          class Allocator = std::allocator<std::pair<Key, T>>,
    //          class ValueTypeContainer = std::vector<std::pair<Key, T>, Allocator>,
    //          class IndexType = std::uint_least32_t>
    //using ordered_map_v = ordered_map<Key, T, Hash, KeyEqual, Allocator, ValueTypeContainer, IndexType>;
    //}


//#include "ds/ktprime/emhash/hash_table8.hpp"
//#include "ds/greg7mdp/parallel_hashmap/phmap.h"

// wyhash is very Fast hash without quality problems. It is very fast and good PRNG also.
// wyhash is the default hashing algorithm of the great Zig, V, Nim and Go (since 1.17) language 
// and deployed by Microsoft on [Windows Terminal]
    //#include "ds/wyhash/wyhash_all.h"

//--------------------------------------
// Random Nunber Generators (RNG)
// Mersenne Twister 1997 original version 64bit & 32bit in one header.
//#include "ds/rand/mt19937/mt19937.h"

// xoshiro256** is the family's general-purpose random 64-bit number generator. 
// It is used in GNU Fortran compiler, Lua, and the .NET framework (as of .NET 6.0)
//#include "ds/rand/xoshiro/xoshiro256starstar.h"


//--------------------------------------
// hash speed
//-https://github.com/Cyan4973/xxHash
//Hash Name 	Width 	Bandwidth (GB/s) 	Small Data Velocity 	SMHasher Quality
//MD5 	        128 	0.6 GB/s 	        7.8 	                10
//SHA1 	        160 	0.8 GB/s 	        5.6 	                10
//FNV64 	    64 	    1.2 GB/s 	        62.7 	                5
//Murmur3 	    32 	    3.9 GB/s 	        56.1 	                10 	
//SpookyHash 	64 	    19.3 GB/s 	        53.2 	                10
//City64 	    64 	    22.0 GB/s 	        76.6 	                10
//XXH64 	    64 	    19.4 GB/s 	        71.0 	                10
//XXH3 (SSE2) 	64 	    31.5 GB/s 	        133.1 	                10
//-------------------------- 		
//-https://github.com/rurban/smhasher
//Hash function 	MiB/sec 	
//--------------------------					
//crc32 	        383.12
//md5_64 	        351.01
//sha1_64 	        353.03
//FNV1a 	        762.10
//djb2 bernstein 	1014.45
//sdbm 	            770.27
//Murmur3A 	        3037.83
//City64 	        14011.88
//City64low 	    13897.36
//xxHash64 	        12226.39
//xxh3 	            20383.53	
//SpookyV2_64 	    13104.98
//wyhash 	        22513.04
//--------------------------------------
// hash quality
//-https://aras-p.info/blog/2016/08/02/Hash-Functions-all-the-way-down/
//“Words” - just a dump of English words (/usr/share/dict/words). 235886 entries, 2.2MB total size, average length 9.6 byte
//Hash 	        Words collis 	
//djb2 	        10 	
//FNV 	        5 	
//CRC32 	    5
//Murmur3-32 	3 
//SpookyV2-64 	0 	
//xxHash64 	    0 

//--------------
//#include "ds/hash/fnv1a_hash.h"
//#include "ds/hash/MurmurHash3.h"
//#include "ds/hash/SpookyV2.h"
