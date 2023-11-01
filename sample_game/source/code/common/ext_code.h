#pragma once


#if 0
%c 	character
%d 	decimal (integer) number (base 10)
%e 	exponential floating-point number
%f 	floating-point number
%i 	integer (base 10)
%o 	octal number (base 8)
%s 	a string of characters
%u 	unsigned decimal (integer) number
%x 	number in hexadecimal (base 16)
%% 	print a percent sign
\% 	print a percent sign
#endif

// std::format
int a = 1;
println("Hello {{{}}}.\n", a); //Hello {1}.

//char result[16];
////strcpy(result, get_filename_ext("test.tif"));
//get_filename_ext(result, "test.tiff");
////printf("%s\n", result);
////gout << result << qwe << sdf;
//printf("%s\n", result);

// Sample c sript
const char* cfgc = 
R"(
float add(float a, float b) { 
	a = a * 5; 
	return a + b; 
}
float c = 4.0;
float d = 5.0;
float e = add(c, d);
float f = e + d;
printf("%.3f, %f\n", e, f);
float g = sin(d);
printf("%f\n", g);
// config
int posx = 10;
int posy = 50;
int width = 800;
int height = 450;
bool fullscreen = false;
const char* wnd_title = "Win Sample";
printf("%s\n", wnd_title);
)";


//=============================================
class vec3 {
public:
	//union
	//{
	//	struct { float x, y, z; };
	//	float e[3];
	//};	

	float x, y, z;
	//vec3(float x, float y, float z) : e {x, y, z} {}	
	//vec3(float x, float y, float z) : x(x), y(y), z(z) {}
};

class color4 {
public:
	//union
	//{
	//	float r, g, b, a;
	//	vec4 v;
	//};
	float r, g, b, a;
};

class mat4 {
public:
	union {
        //struct {
        //    float	m11, m12, m13, m14,
			     //   m21, m22, m23, m24,
			     //   m31, m32, m33, m34,
			     //   m41, m42, m43, m44;
        //};
		float e[16];
		//float r[4][4];
	};
};

union vec4 {
   struct {
      float x;
      float y;
      float z;
      float w;
   };
   struct {
      float r;
      float g;
      float b;
      float a;
   };
   float data[4]; /* good for math macros */
};
//---------------------------
// D3D11 Vertex formats
struct vertex_nct
{
	DirectX::XMFLOAT3 Pos;
	DirectX::XMFLOAT3 Normal;
	DirectX::XMFLOAT2 Tex;
	DirectX::XMFLOAT3 TangentU;
};

struct Terrain
{
	DirectX::XMFLOAT3 Pos;
	DirectX::XMFLOAT2 Tex;
	DirectX::XMFLOAT2 BoundsY;
};

struct Particle
{
	DirectX::XMFLOAT3 InitialPos;
	DirectX::XMFLOAT3 InitialVel;
	DirectX::XMFLOAT2 Size;
	float Age;
	unsigned int Type;
};

struct AmbientOcclusion
{
	DirectX::XMFLOAT3 Pos;
	DirectX::XMFLOAT3 Normal;
	DirectX::XMFLOAT2 Tex;
	float AmbientAccess;
};

struct PosNormalTexTanSkinned
{
	DirectX::XMFLOAT3 Pos;
	DirectX::XMFLOAT3 Normal;
	DirectX::XMFLOAT2 Tex;
	DirectX::XMFLOAT4 TangentU;
	DirectX::XMFLOAT3 Weights;
	BYTE BoneIndices[4];
};

//=============================================
// martinus unordered_dense
#include <ankerl/unordered_dense.h>
#include <iostream>
auto main() -> int {
    auto map = ankerl::unordered_dense::map<int, std::string>();
    map[123] = "hello";
    map[987] = "world!";

    for (auto const& [key, val] : map) {
        std::cout << key << " => " << val << std::endl;
    }
}

//=============================================
//tessil sparse map, memory efficient, fast enough
tsl::sparse_map<std::string, int> map = {{"a", 1}, {"b", 2}};
map["c"] = 3;
map["d"] = 4;    
map.insert({"e", 5});
map.erase("b");
for(auto it = map.begin(); it != map.end(); ++it) {
    //it->second += 2; // Not valid.
    it.value() += 2;
}    
auto it = map.find("b");
if(it != map.end()) {
    println("{},{}", it->first, it->second);
}
// {d, 6} {a, 3} {e, 7} {c, 5}
for(const auto& key_value : map) {
    println("[{},{}]", key_value.first, key_value.second);
} 
if(map.find("a") != map.end()) {
    println("Found \"a\".");
}
const std::size_t precalculated_hash = std::hash<std::string>()("a");
// If we already know the hash beforehand, we can pass it as argument to speed-up the lookup.
if(map.find("a", precalculated_hash) != map.end()) {
    println("Found \"a\" with hash {}.", precalculated_hash);
}   

//--------------------
tsl::ordered_map_v<std::string, int> ab1;
ab1.insert({"one", 1});
ab1.insert({"two", 2});
ab1.insert({"three", 3});
ab1.insert({"four", 4});
ab1.insert({"five", 5});
for (auto const &k: ab1) {
	println("{}", k.second);
}
q_print_sep_line();
for_range (i, 0, ab1.values_container().size()) {
	println("{}", ab1.values_container()[i].second);
}
//=============================================
// only for pod
template <class T>
class selfzero : public T
{
public:
    selfzero() {
        ZeroMemory( this, sizeof( selfzero<T> ));
    };
};

selfzero<STARTUPINFO> si;

//=============================================
// pass a pointer by reference
#include <iostream>
void test(int*& t)
{
    t = nullptr;
}

int main()
{
    int* i = new int(4);

    test(i);

    if (i == nullptr)
        std::cout << "I was passed by reference" << std::endl;
}
//---
void func(int **p)
{
    if (p != NULL) {
        free(*p);
        *p = NULL;
    }
}

int *p = someConstructor();
func(&p);
// here 'p' will actually be NULL
//---
//string sso

isz m_size = 0;
union {
	struct {
		char* m_data;
		isz m_capacity;
	}; //m_large;
	//char m_small[sizeof(m_large)];
	char m_small[16];
};

string() { m_small[0] = '\0'; m_capacity = 1; }
const char* data() const		{ if (m_capacity==1) { return m_small; } else { return m_data; } }
char* data()					{ if (m_capacity==1) { return m_small; } else { return m_data; } }
//=============================================
Expected<int> divide(int num, int denom)
{
    if (denom == 0)
    {
        return Expected<int>(0, "Divide by Zero Error.");
    }
    else 
    {
        return Expected<int>(num/denom);
    }
}
//---
Expected<int> q;
q = divide(3, 2);
if (q.is_ok()) { std::cout << "division result: " << q.result() << std::endl; }
else { std::cout << q.err() << std::endl; }
q = divide(3, 0);
if (q.is_ok()) { std::cout << "division result: " << q.result() << std::endl; }
else { std::cout << q.err() << std::endl; }

//---------------------------
if(!win_app::register_window_class(nw_app))
{
    std::printf("Cannot register Window Class\n");
    goto label_main_exit;
}

try
{
    win_app::register_window_class(nw_app);
}
catch (std::exception e)
{
    std::cout << e.what() << std::endl;
    //goto label_main_exit;
}

//-----------------------
// custom sort by field in std::list
struct data {
    int num, pri;
    bool operator<(const data& b ) const { return pri < b.pri; }
};
struct Functor {
    bool operator()(const data& a, const data& b ) { return a.pri < b.pri; }
};
int main()
{
    sdr::list<data> lst;
    lst.push_back(data(0, 5));
    lst.push_back(data(1, 3));
    lst.push_back(data(2, 1));
    lst.push_back(data(3, 2));
    lst.push_back(data(4, 4));
    
    lst.sort();
    //Functor f;
    //lst.sort(f);
    //std::sort(lst.begin(), lst.end());

    for (const auto &it: lst) {
        println("{}, {}", it.num, it.pri);
    }
}

//---
#if 0
struct sresult
{
	bool success = true;
	const char* error_msg = nullptr;

    sresult(bool success, const char* error) 
    {
	    this->success = success;
        error_msg = error;
    }

    void set_err(bool success, const char* error)
    {
        success = false;
        if (error_msg == nullptr)
        {
            error_msg = "EROR NOT SET";
        }
        else
        {
            error_msg = error;        
        }
    }

    bool is_ok()
    {
        return success;
    }

	bool is_err()
    {
        //std::cout << success << std::endl;
        return !success;
    }


    const char* err()
    {
        return error_msg;
    }
};

sresult default_sresult(true, "Default error object: Value not set");


int divide(int num, int denom, sresult& err_obj = default_sresult)
{
    if (denom == 0)
    {
        err_obj.set_err(false, "Divide by Zero Error.");
        return 0;
    }
    else 
    {
        return num/denom;
    }
}
#endif


//=============================================

/* getenv example: getting path */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* getenv */
int main ()
{
  char* pPath;
  pPath = getenv ("PATH");
  if (pPath!=NULL)
    printf ("The current path is: %s",pPath);
  return 0;
}

//WINDOWS NEHE
case WM_ACTIVATE:							
	//The low-order word specifies whether the window is being activated or deactivated. 
	//The high-order word specifies the minimized state of the window being activated or deactivated.
	//if (!HIWORD(wParam)) { g_av.app_active = true; }
	//else { g_av.app_active = false; }
	//g_av.app_active = (!HIWORD(wParam));
    //if (LOWORD(wParam) == WA_INACTIVE) { active = false; }
    //else { active = true; }
	g_av.app_active = LOWORD(wParam);
	return 0;

// YES/NO MsgBox
// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
if (ChangeDisplaySettings(&dmScreenSettings,CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL)
{
	// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
	if (MessageBox(NULL,"The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?","NeHe GL",MB_YESNO|MB_ICONEXCLAMATION)==IDYES)
	{
		fullscreen=FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
	}
	else
	{
		// Pop Up A Message Box Letting User Know The Program Is Closing.
		MessageBox(NULL,"Program Will Now Close.","ERROR",MB_OK|MB_ICONSTOP);
		return FALSE;									// Return FALSE
	}
}
if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
{
	fullscreen=FALSE;							// Windowed Mode
}

if (g_keys[VK_F1])						
{
	// Is F1 being pressed, make key FALSE
	g_keys[VK_F1] = false;					
	KillGLWindow();			
	// Toggle Fullscreen / Windowed Mode
	fullscreen = !fullscreen;				
	// Recreate Our OpenGL Window
	CreateGLWindow("NeHe's OpenGL Framework",640,480,16,fullscreen);
}

// pointers instead ofsmart pointers for win_app and class
//win_app* nw_app = new win_app;
//renderer_d3d9b* rn = new renderer_d3d9b;
//renderer_gl2* rn = new renderer_gl2;
//delete rn;
//delete nw_app;
//=============================================
//C++11
using FunctionFunc = std::function<void(int arg1, std::string arg2)>;
//without C++11 using keyword would be like 
typedef std::function<void(int, std::string)> FunctionFunc;

typedef   void      (*FunctionFunc)  ( );
//         ^                ^         ^
//     return type      type name  arguments
FunctionFunc x;
void doSomething() { printf("Hello there\n"); }
x = &doSomething;
x(); //prints "Hello there"

// typedef function pointer
// for (void (CALLBACK *)()) of gluTessCallback
typedef void (CALLBACK *glu_tess_cb_type)();

//-----------------------------------
typedef int (*t_somefunc)(int,int);

int product(int u, int v) 
{ 
  return u*v;
}

t_somefunc afunc = &product;

int x2 = (*afunc)(123, 456); // call product() to calculate 123*456


//-----------------------------------
// Unicode in Windows console program
SetConsoleOutputCP(CP_UTF8);    
wchar_t text[512];
wscanf(L"%s", text);
wprintf(L"%s", text);
//=============================================
// Loop over enum values
// old-school enums:
for ( E x = minval ; x <= maxval ; x = E(x+1) ) {}

//enum class
enum class{
    ...,
    Count
}
const int enum_max{static_cast<int>(EEnum::Count)}
for ( int x = 0 ; x < enum_max; ++x ) {
    const EEnum cur_enum{static_cast<EEnum>(x)}
}
//=============================================
//int len = 50;
//char* start = (char*)malloc(sizeof(char)*len);
//gout << "*start total: " << sizeof(*start)*len << ", start: " << sizeof(start) << QEL << sdf;



/*farray<char> ta;
ta.size = 64;
ta.data = (char*)malloc(sizeof(char)*ta.size);
gout << "*tbuffer ta - total bits: " << sizeof(*ta.data)*ta.size << ", ta.data: " << sizeof(ta.data) << QEL << sdf;

ta.data[0] = 65;
gout << ta.data[0] << QEL << sdf;*/

class fpool
{
public:
	int size_bits;
	int elem_size;
	int elem_per_block;
	char* data;

};

fpool ta;
//ta.block_size = 8;
ta.elem_size = sizeof(int);
ta.elem_per_block = 16;
ta.size_bits = ta.elem_size * ta.elem_per_block;
//ta.size = 72;
ta.data = (char*)malloc(sizeof(char)*ta.size_bits);
//gout << "*tbuffer ta - total bits: " << sizeof(*ta.data)*ta.size_bits << ", ta.size_bits: " << ta.size_bits << ", elem_size: " << ta.elem_size 
//	<< ", elem_per_block: " << ta.elem_per_block << QEL << sdf;
//ta.data[0] = 65;
//gout << (double)ta.data[0] << QEL << sdf;

int* pfa = nullptr;
pfa = (int*)ta.data;
pfa[0] = 32;
//gout << pfa[0] << QEL << sdf;



char nts1[] = "Test";
gout << get_hash(nts1) << QEL << sdf;



farray<int> tb;
//tb.size = 64;
//tb.data = (int*)malloc(sizeof(int)*tb.size);
tb.allocate(64);
//gout << "*tbuffer ta - total: " << sizeof(*tb.data)*tb.size << ", ta.data: " << sizeof(tb.data) << QEL << sdf;
gout << "*tbuffer ta - total bits: " << tb.get_size_bits() << ", total size: " << tb.get_size() << ", ta.data: " << sizeof(tb.data) << QEL << sdf;

//tb.data[0] = 65;
//gout << tb.data[0] << QEL << sdf;

//tb.set_element(0, 65);
//tb.data[0] = 65;
tb[0] = 65;
gout << tb.at(0) << QEL << sdf;
tb.deallocate();

pool_array<int> tc(32);
//tc.elem_per_block = 32;
//tc.allocate(32);
//tb.data[0] = 65;
//gout << tb.data[0] << QEL << sdf;

tc.insert(325, 65);
//tc.data_list[0][32] = 65;
//tb[0] = 65;
gout << tc.at(325) << QEL << sdf;

gout << "*tbuffer tc - total bits: " << tc.get_size_bits() << ", total size: " << tc.get_size() << ", tc.data: " << sizeof(tc.data_list[0][0]) << QEL << sdf;
tc.deallocate();


//Setting unused pointers to NULL is a defensive style, protecting against dangling pointer bugs. 
//If a dangling pointer is accessed after it is freed, you may read or overwrite random memory. 
//If a null pointer is accessed, you get an immediate crash on most systems, telling you right away what the error is.
//void myfree(void **ptr)
//{
//    free(*ptr);
//    *ptr = NULL;
//}

//=============================================

//----------------
#define _GLFW_SWAP_POINTERS(x, y, type) \
    {                             \
        type* t;                  \
        t = x;                    \
        x = y;                    \
        y = t;                    \
    }
    int a, b;
    int *pa = &a, *pb = &b;
    println("{}, {}", static_cast<void*>(pa), static_cast<void*>(pb));
    std::cout << static_cast<void*>(pa) << ", " << static_cast<void*>(pb) << "\n";
    //printf("%p, %p\n", pa, pb);
    std::swap(pa, pb);
    printf("%p, %p\n", pa, pb);
//=============================================================
//djb2
//this algorithm (k=33) was first reported by dan bernstein many years ago in comp.lang.c. another version of this algorithm (now favored by bernstein) uses xor: hash(i) = hash(i - 1) * 33 ^ str[i]; 
//the magic of number 33 (why it works better than many other constants, prime or not) has never been adequately explained.

    unsigned long
    hash(unsigned char *str)
    {
        unsigned long hash = 5381;
        int c;

        while (c = *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
    }

//sdbm
//this algorithm was created for sdbm (a public-domain reimplementation of ndbm) database library. it was found to do well in scrambling bits, causing better distribution of the keys and fewer splits. 
//it also happens to be a good general hashing function with good distribution. the actual function is hash(i) = hash(i - 1) * 65599 + str[i]; what is included below is the faster version used in gawk. 
//[there is even a faster, duff-device version] the magic constant 65599 was picked out of thin air while experimenting with different constants, and turns out to be a prime. this is one of the algorithms 
// used in berkeley db (see sleepycat) and elsewhere.

    static unsigned long
    sdbm(str)
    unsigned char *str;
    {
        unsigned long hash = 0;
        int c;

        while (c = *str++)
            hash = c + (hash << 6) + (hash << 16) - hash;

        return hash;
    }

//lose lose
//This hash function appeared in K&R (1st ed) but at least the reader was warned: "This is not the best possible algorithm, but it has the merit of extreme simplicity." This is an understatement;
//It is a terrible hashing algorithm, and it could have been much better without sacrificing its "extreme simplicity." [see the second edition!] Many C programmers use this function without actually 
// testing it, or checking something like Knuth's Sorting and Searching, so it stuck. It is now found mixed with otherwise respectable code, eg. cnews. sigh. [see also: tpop]

    unsigned long
    hash(unsigned char *str)
    {
	unsigned int hash = 0;
	int c;

	while (c = *str++)
	    hash += c;

	return hash;
    }

//--------------------------
// SPAN
//--------------------------
void strf1(const char* p, isz len) {
	printf("strf1: %s\n", p);
}
void strf2(sdf::cspan<char> as) {
	strf1(as.data(), as.size());
	printf("strf2: %s\n", as.data());
}

void choose_int(const int* alternatives, isz alternatives_count) {
	const int* current_fb_cfg = nullptr;
	for (isz i = 0;  i < alternatives_count;  i++) {
		current_fb_cfg = &alternatives[i];
		//dprintln("{}", *current_fb_cfg);
		dprintln("{}: {}", i, alternatives[i]);
		//alternatives[1] = 55; //const int* stops this
	}
	//return current_fb_cfg;
}

void choose_int2(sdf::span<int> alternatives) {
	choose_int(alternatives.data(), alternatives.size());
	//const int* current_fb_cfg = nullptr;
	//for (isz i = 0;  i < alternatives.size();  i++) {
	//	current_fb_cfg = &alternatives[i];
	//	//dprintln("{}", *current_fb_cfg);
	//	dprintln("{}", alternatives[i]);
	//}
	// cannot modify if using cspan.
	alternatives[1] = 55;
	auto pos = alternatives.find_index(53);
    if (pos) {
        println("value at: {}", pos.value());
    } else {
		println("value not found");
	}
	//return current_fb_cfg;
}

	//char fg[4];
	char fg[] = "Hello world";
	const char* ptfg = fg;
	sdf::vector<int> cfgs;
	cfgs.push_back(1);
	cfgs.push_back(2);
	cfgs.push_back(3);
	//int* di = (int*)malloc(8*sizeof(char));
	//choose_int(di, 8);
	//choose_int2(sdf::span<int>(di, 8));
	choose_int2(sdf::to_span(cfgs.data(), cfgs.size()));
	cfgs.print_data();
	//const char* b = "HELLO";
	//strf2(sdf::cspan<char>(b, 6));

//----------------------------------------------------
// overload the operator++ in two different ways for postfix a++ and prefix ++a
class Number {
    public:
        // prefix ++
        Number& operator++ () {
           // Do work on this.   (increment your object here)
           return *this;
        }

        // You want to make the ++ operator work like the standard operators
        // The simple way to do this is to implement postfix in terms of prefix.
        //
        // postfix ++
        Number  operator++ (int) {
           Number result(*this);   // make a copy for result
           ++(*this);              // Now use the prefix version to do the work
           return result;          // return the copy (the old) value.
        }
}; 

//---
// Assignement operator
// Copy Swap idiom
vector& operator=(const vector& other) {
    // check for self assignment.
    if (this != &other) {
        vector temp(other); // Copy-constructor -- RAII
        temp.swap(*this); // Non-throwing swap
        // or
        //vector(other).swap(*this); //Copy-constructor and non-throwing swap
    }      
    // Old resources are released with the destruction of the temporary above
    return *this;
}

iterator operator++(int) noexcept {
    iterator temp = (*this);
    ++(*this);
    return temp;
}
iterator operator--(int) noexcept {
    iterator temp = (*this);
    --(*this);
    return temp;
}

//--------------------------
// std::pmr allocators
//--------------------------
    //pmr allocators

    char buffer1[64] = {}; // a small buffer on the stack
    std::fill_n(std::begin(buffer1), std::size(buffer1) - 1, '_');
    println("{}\n", buffer1);

    // Arena allocator, Bump pointer allocator:
    // Releases the allocated memory only when the resource is destroyed. IUsed where memory is used to build up a few objects and then is released all at once.
    // monotonic_buffer_resource can be constructed with an initial buffer. If there is no initial buffer, or if the buffer is exhausted, additional buffers are 
    // obtained from an upstream memory resource supplied at construction. The size of buffers obtained follows a geometric progression. 
    std::pmr::monotonic_buffer_resource pool1{std::data(buffer1), std::size(buffer1)};
    // Pool allocator: 
    // Consists of a collection of pools that serves requests for different block sizes.
    // Exhausting memory in the pool causes the next allocation request for that pool to allocate an additional chunk of
    // memory from the upstream allocator to replenish the pool. The chunk size obtained increases geometrically. 
    // Each pool manages a collection of chunks that are then divided into blocks of uniform size. 
    // max_blocks_per_chunk: maximum number of blocks that will be allocated at once from the upstream std::pmr::memory_resource to replenish the pool.
    // largest_required_pool_block: largest allocation size that is required to be fulfilled using the pooling mechanism.
    //std::pmr::unsynchronized_pool_resource pool2{};
    //std::pmr::synchronized_pool_resource pool2{}; //thread safe

    std::pmr::vector<char> vec1{ &pool1 };
    vec1.reserve(63);
    for_range(i, 3) {
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            vec1.push_back(ch);
        }
    }

    for (const auto &a: vec1) {
        print("{}", a);
    }
    println("");
    println("{}", buffer1);

    //----------------------------------
    //println("sizeof(std::string): {}", sizeof(std::string));
    //println("sizeof(std::pmr::string): {}", sizeof(std::pmr::string));

    //char buffer2[256] = {}; // a small buffer on the stack
    //std::fill_n(std::begin(buffer2), std::size(buffer2) - 1, '_');

    //const auto BufferPrinter = [](std::string_view buf, std::string_view title) { 
    //    println("{}:", title);
    //    for (auto& ch : buf) {
    //        print("{}", (ch >= ' ' ? ch : '#'));
    //    }
    //    println("");
    //};

    //BufferPrinter(buffer2, "zeroed buffer");
    //std::pmr::monotonic_buffer_resource pool2{std::data(buffer2), std::size(buffer2)};
    //std::pmr::vector<std::pmr::string> vec2{ &pool2 };
    //vec2.reserve(5);

    //vec2.push_back("Hello World");
    //vec2.push_back("One Two Three");
    //BufferPrinter(std::string_view(buffer2, std::size(buffer2)), "after two short strings");
    //vec2.emplace_back("This is a longer string");
    //BufferPrinter(std::string_view(buffer2, std::size(buffer2)), "after longer string strings");
    //vec2.push_back("Four Five Six");
    //BufferPrinter(std::string_view(buffer2, std::size(buffer2)), "after the last string");


//--------------------------
// Get type of element of vector
std::vector<uint>::value_type;
//In case you are actually inside templated code 
typename std::vector<T>::value_type;
// In C++11, you can use 
sizeof(decltype(vecs)::value_type);
//or also 
sizeof(decltype(vecs.back()));



//--------------------------
// DS
//--------------------------

// ord_map
sdf::ord_map<sdr::string, float> am;
	am.reserve(10);
	am.insert({"one", 1.1});
	am.insert({"two", 2.1});
	am.insert({"three", 3.1});
	am.insert({"four", 4.1});
	am.insert_at("two", {"new", 15.1});
	am.erase("two");

	println("{}", am.find("two").value_or(0));
	println("{}", am.find("four").value_or(0));

	for_range(i, 0, am.data_vec.size()) {
		print("[{}], ", am.data_vec[i]);
	}
	println("\n---");
	for(const auto& elem : am.key_index_map) {
		print("-[{}, {}, {}]-, ", elem.first, elem.second, am.find(elem.first).value_or(0));
	}
	println("\n---");

	tsl::ordered_map<sdr::string, float> am2;
	am2.insert({"one", 1.1});
	am2.insert({"two", 2.1});
	am2.insert({"three", 3.1});
	am2.insert({"four", 4.1});
	am2.insert_at_position(am2.cbegin() + 2, {"new", 15.1});


	for(const auto& elem : am2) {
		print("-[{}, {}]-, ", elem.first, elem.second);
	}


//-------------------------------------
// sdf::vector 3 modes
	sdf::vector<int> a1(2);
	for_range(i, 4) { a1.push_back(i); }
	print_sc(a1);
	print_dt(a1);
	sdf::vector<int> b1(2, sdf::vgrowth_e::fixed_dynamic);
	for_range(i, 4) { b1.push_back(i); }
	print_sc(b1);
	print_dt(b1);
	int c1_buffer[2];
	sdf::vector<int> c1(c1_buffer, sdf::arr_cap(c1_buffer));
	for_range(i, 4) { c1.push_back(i); }
	print_sc(c1);
	print_dt(c1);
	//-------------------------------------


	sdf::string s1; 
	s1.resize(20);
	//s1.reserve(20);
	//sdf::string s1(4);
	//sdf::string s1(4, sdf::vgrowth_e::fixed_dynamic);
	//s1.print_stats();
	print_sc(s1); 
	s1.resize(20);
	print_sc(s1); 
	s1.assign("12");
	print_sc(s1);
	print_dt(s1.c_str());
	s1.append("34562222222222222222222222222222222222222222222222222");
	print_sc(s1);
	print_dt(s1.c_str());
	s1.resize(20);
	//print_sc(s1); s1.resize_exact(20);
	print_sc(s1);
	s1.shrink_to_fit();
	print_sc(s1);

    // resize, reserve allocation check
    sdf::vector<int> a;
	print_sc(a);
	a.push_back(2);
	print_dt(a);
	print_sc(a);
	a.reserve_exact(0);
	print_sc(a);
	a.reserve_exact(10);
	print_sc(a);
	a.resize_exact(30);
	print_sc(a);
	a.resize_exact(33);
	print_sc(a);
	a.resize_es(0);
	print_sc(a);
	a.resize_es(10);
	print_sc(a);
	a.resize_es(11);
	print_sc(a);
	a.resize_es(30);
	print_sc(a);
	a.resize_es(33);
	print_sc(a);
	a.resize_es(9);
	print_sc(a);
	a.resize_es(20);
	print_sc(a);


//-------------------------------------------------
// sdf::vector move constructor, move assigne,ment, iterators, std::sort
void test2(const sdf::vector<int>& av) {
	for (auto &i : av) {
		//i = 1;
	}

	//for (int i=0; i < av.size(); ++i) {
	//	av[i] = 1;
	//}

	for (auto i : av) {
		println("{}", i);
	}

	//for (int i=0; i < av.size(); ++i) {
	//	println("{}", av[i]);
	//}

	println("\n---");
}
sdf::vector<int> generateResource() {
	sdf::vector<int> res;
	res.push_back(1);
	res.push_back(3);
	res.push_back(5);
	res.push_back(7);
	return res; // this return value will invoke the copy constructor
}

#include <algorithm>

	sdf::vector<int> av;
	av.push_back(4);
	av.push_back(3);
	av.push_back(7);
	av.push_back(6);

	test2(av);

	std::sort(av.begin(), av.end());

	for (auto i : av) { println("{}", i); } println("\n---");

	for (auto it = (--av.end()); it != (--av.begin()) ; --it) {
        println("{}", *it);
    }
	println("\n---");

	sdf::vector<int> mainres;
	mainres = generateResource(); // call move assignement
	for (auto i : mainres) { println("{}", i); } println("\n---");
	sdf::vector<int> mainres2(std::move(generateResource())); // call move constructor
	//-sdf::vector<int> mainres2(static_cast<sdf::vector<int>&&>(generateResource())); // call move constructor
	for (auto i : mainres2) { println("{}", i); } println("\n---");

//--------------------------
// MATH TEST
//--------------------------
    //gm::vec3 a(1, 2, 3);
    //gm::vec3 b = -a;
    //println("{}, {}, {}", b.x, b.y, b.z);
    //println("---------------------");

    //gm::mat4 ma(1,2,3,4, 9,10,11,12, 5,6,7,8,    13,14,15,16);
    //gm::mat4 mb(1,2,3,4, 5,6,7,8,    9,10,11,12, 13,14,15,16);
    //compare_print(
    //    gm::mat4_mul(ma, mb),
    //    gm::mat4_mul_2(ma, mb)
    //    );
    //gm::vec4 va(8,9,6,5);
    //str(gm::mat4_mul_vec4(ma, va)).print_data();
    //str(gm::mat4_mul_vec4_2(ma, va)).print_data();
    //gm::mat4 mi(1,2,3,-4, 5,6,-7,8,    9,-10,11,12, -13,14,15,16);
    //println("{}", mat4_determinant(mi));
    ////println("{}", mat4_determinant_d3dx9(mi));
    //str(gm::mat4_inverse(mi).value()).print_data();
    ////str(gm::mat4_inverse_d3dx9(mi).value()).print_data();
    //str(gm::mat4_rotation_yaw_pitch_roll(1, 5, 6)).print_data();
    ////str(gm::mat4_rotation_yaw_pitch_roll_2(1, 5, 6)).print_data();
    //gm::quat qa(2.3, 8.6, 5.6, 8.9); gm::quat qb(8.6, 5.4, 2.3, 7.8); float s = 3.5;
    //str(gm::quat_slerp(qa, qb, s)).print_data();
    //str(gm::quat_slerp_2(qa, qb, s)).print_data();
    //str(gm::quat_from_rotation_mat4_2(ma)).print_data();
    //str(gm::quat_from_rotation_mat4(ma)).print_data();

    // CHECK:
    float fovy = 55.4; float aspect = 16.0/9.0; float zn = 1.2; float zf  = 102.3;
    gm::vec3 position(1.2, 8.6, 9.4); gm::vec3 target(2.3, 8.4, 6.4); gm::vec3 up(8.1, 9.2, 6.3);
    float w = 320.2; float h = 640.5; //float zn, float zf;
    float left = 1.2; float right = 2.3; float bottom = 4.2; float top = 6.8; //float zn, float zf
    gm::vec4 light(2.8, 6.4, 5.2, 3.5); gm::plane pa(5.2, 6.3, 4.8, 5.6);
    gm::quat qa(2.5, 8.9, 5.6, 4.7);

    D3DXVECTOR3 positionx(1.2, 8.6, 9.4); D3DXVECTOR3 targetx(2.3, 8.4, 6.4); D3DXVECTOR3 upx(8.1, 9.2, 6.3);
    D3DXVECTOR4 lightx(2.8, 6.4, 5.2, 3.5); D3DXPLANE pax(5.2, 6.3, 4.8, 5.6);
    D3DXQUATERNION qax(2.5, 8.9, 5.6, 4.7);
    D3DXMATRIX out;
    D3DXMatrixIdentity(&out);   
    

    compare_print(
        gm::mat4_perspective_fov_lh(fovy, aspect, zn, zf),
        D3DXMatrixPerspectiveFovLH(&out, fovy, aspect, zn, zf)
    );
    D3DXMatrixIdentity(&out);
    compare_print(
        gm::mat4_perspective_fov_rh(fovy, aspect, zn, zf),
        D3DXMatrixPerspectiveFovRH(&out, fovy, aspect, zn, zf)
    );
    D3DXMatrixIdentity(&out);
    compare_print(
        gm::mat4_look_at_lh(position, target, up),
        D3DXMatrixLookAtLH(&out, &positionx, &targetx, &upx)
    );
    D3DXMatrixIdentity(&out);
    compare_print(
        gm::mat4_look_at_rh(position, target, up),
        D3DXMatrixLookAtRH(&out, &positionx, &targetx, &upx)
    );
    D3DXMatrixIdentity(&out);
    compare_print(
        gm::mat4_perspective_lh(w, h, zn, zf),
        D3DXMatrixPerspectiveLH(&out, w, h, zn, zf)
    );
    D3DXMatrixIdentity(&out);
    compare_print(
        gm::mat4_perspective_rh(w, h, zn, zf),
        D3DXMatrixPerspectiveRH(&out, w, h, zn, zf)
    );
    D3DXMatrixIdentity(&out);
    compare_print(
        gm::mat4_perspective_offcenter_lh(left, right, bottom, top, zn, zf),
        D3DXMatrixPerspectiveOffCenterLH(&out, left, right, bottom, top, zn, zf)
    );
    D3DXMatrixIdentity(&out);
    compare_print(
        gm::mat4_perspective_offcenter_rh(left, right, bottom, top, zn, zf),
        D3DXMatrixPerspectiveOffCenterRH(&out, left, right, bottom, top, zn, zf)
    );
    D3DXMatrixIdentity(&out);
    compare_print(
        gm::mat4_ortho_lh(w, h, zn, zf),
        D3DXMatrixOrthoLH(&out, w, h, zn, zf)
    );
    D3DXMatrixIdentity(&out);
    compare_print(
        gm::mat4_ortho_rh(w, h, zn, zf),
        D3DXMatrixOrthoRH(&out, w, h, zn, zf)
    );
    D3DXMatrixIdentity(&out);
    compare_print(
        gm::mat4_ortho_offcenter_lh(left, right, bottom, top, zn, zf),
        D3DXMatrixOrthoOffCenterLH(&out, left, right, bottom, top, zn, zf)
    );
    D3DXMatrixIdentity(&out);
    compare_print(
        gm::mat4_ortho_offcenter_rh(left, right, bottom, top, zn, zf),
        D3DXMatrixOrthoOffCenterRH(&out, left, right, bottom, top, zn, zf)
    );
    D3DXMatrixIdentity(&out);
    compare_print(
        gm::mat4_shadow(light, pa),
        D3DXMatrixShadow(&out, &lightx, &pax)
    );
    D3DXMatrixIdentity(&out);
    compare_print(
        gm::mat4_reflection(pa),
        D3DXMatrixReflect(&out, &pax)
    );
    D3DXMatrixIdentity(&out);
    compare_print(        
        gm::mat4_rotation_axis(va, angle),
        D3DXMatrixRotationAxis(&out, &vax, angle)
    );
    D3DXMatrixIdentity(&out);

    compare_print(
        gm::mat4_from_rotation_quat(qa),
        D3DXMatrixRotationQuaternion(&out, &qax)
    );
    D3DXMatrixIdentity(&out);


    str(gm::quat_from_rotation_mat4(ma)).print_data(); //d3dx
    //str(gm::quat_from_rotation_mat4_2(ma)).print_data();

//------------------------------------------------------------------