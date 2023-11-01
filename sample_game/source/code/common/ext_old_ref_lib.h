#pragma once

#if 0
//FILE _READING
//checking whether the file is open
//std::string line_buffer;
//getline(newfile, line_buffer); std::cout << line_buffer << "\n";
//getline(newfile, line_buffer); std::cout << line_buffer << "\n";
//while(getline(newfile, line_buffer))
//{
//    //auto first_token = line_buffer.substr(0, line_buffer.find(' '));
//    //std::cout << first_token << "\n";
//
//    std::istringstream iss(line_buffer);
//    std::string item;
//    while (std::getline(iss, item, ' ')) 
//    {
//        std::cout << item << "\n";
//    }   
//}

//==============================================================
//LINUX
#include <unistd.h>
#include <termios.h>
char getch(void)
{
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if(tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if(tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if(read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if(tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    printf("%c\n", buf);
    return buf;
 }

//==============================================================
template<class T>	//, class E = fresult_error_t>
class fresult1
{
public:
	union
	{
		T m_value;
		fr_error m_error;
	}; 
	bool m_has_value = true;

	bool failed() { return !m_has_value; }

	fresult1() {}   

    // Success case
	fresult1(const T& value) : m_value{ value }, m_has_value{ true } {}
	fresult1(T&& value) : m_value{ std::move(value) }, m_has_value{ true } {}

	// Error case
    //fresult1(fnullopt_t, const char* err_msg) 
    //fresult1(fr_error error) 
    //: m_has_value(false) 
    //{
    //    sdf::str_copy(m_error.m_err_msg, error.m_err_msg, m_error.k_m_buf_size);
    //}

	fresult1(fr_error error) : m_error{ error }, m_has_value{ false } {}
	//fresult1(const char* err_msg) : m_error{ err_msg }, m_has_value{ false } {}

	//~fresult1() { destroy(); }
};

template<class T>
class fresult
{
public:
	static const int k_m_buf_size = 256;

#if 0
    // Can contain default value & error also.
	bool m_has_value = true;
	char m_err_msg[k_m_buf_size] = {};
    T m_value;
#else

    union
	{
		T m_value;
		char m_err_msg[k_m_buf_size] = {};
	}; 
	bool m_has_value = true;
#endif

    // Success case
    //fresult(T value) { m_value = value; }

    // Error case
  //  fresult(T default_value, const char* err_msg)
  //  {
  //      m_has_value = false;
		//sdf::str_copy(m_err_msg, err_msg, buf_size);
  //      m_value = default_value;        
  //  }

    bool failed() { return !m_has_value; }


	fresult() {}   

    // Success case
    fresult(const T& value)
    : m_has_value(true), m_value(value)
    {}

    // Error case
    fresult(fnullopt_t, const char* err_msg) 
    : m_has_value(false) 
    {
        sdf::str_copy(m_err_msg, err_msg, k_m_buf_size);
    }

    bool has_value() const { return m_has_value; }
	//explicit operator bool() const { return m_has_value; }

    const T* operator->() const { q_assert_foptional(m_has_value); return &(m_value); }
    T* operator->() { q_assert_foptional(m_has_value); return &(m_value); }

    const T& operator*() const& { q_assert_foptional(m_has_value); return m_value; }
    T& operator*() & { q_assert_foptional(m_has_value); return m_value; }	
	T&& operator*() && { q_assert_foptional(m_has_value); return std::move(m_value); }

    const T& value() const& { q_assert_foptional(m_has_value); return m_value; }
    T& value() & { q_assert_foptional(m_has_value); return m_value; }
    const T&& value() const&& { q_assert_foptional(m_has_value); return std::move (m_value); }
	T&& value() && { q_assert_foptional(m_has_value); return std::move (m_value); }


    const T& value_or(const T& default_val) const& 
    {
        if (!m_has_value) { m_value = default_val; }
        return m_value;        
    }
    T& value_or(const T& default_val) &
    {
        if (!m_has_value) { m_value = default_val; }
        return m_value;
    }

    //fresult make_result(const T& value) { return fresult<T>(value); }    

    const char* err_msg() const { return m_err_msg; }
};

//int ediv(int a, int b) 
fresult<int> ediv(int a, int b) 
{
    if (b==0)
    {
        return fresult<int>(0, q_finfo("div by zero\n"));
    }
    return fresult(a/b);
}
    auto d = ediv(8, 0);
    //if (d.failed()) { 
    //    //gout << d.msg << sdf;
    //    q_err_msg(d.msg);    
    //}
    //else {
    //    gout << d.val << sdf;
    //}
    q_result_check(d);
    gout << d.val << sdf;

//-------------------------
#include <optional>
#if 1
fresult<float> addf(float a, float b) 
{
	if (b!=5) { return a+b; }
	else {
		return fr_error("addf: b = 5.");
	}
}
#else
//std::optional<float> addf(float a, float b) 
foptional<float> addf(float a, float b) 
{
	if (b!=5) { return a+b; }
	else {
		//return fr_error("addf: b = 5.");
		//return std::nullopt;
		return fnullopt;
	}
}
#endif

#if 1
	auto res = addf(2.0f, 5.0f);
    //q_result_check(res);
	if (!res) { print("{}\n", res.err_msg()); }
	else { print("{:6f}\n", res.value()); }
#else
	auto res = addf(2.0f, 5.0f);
	//if (!res.has_value()) 
    if (!res) // == fnullopt)
    { print("addf: b = 5.\n"); }
	else { print("{:6f}\n", res.value()); }
#endif

#include <optional>
double division(int a, int b)
{
   if( b == 0 ) 
   {
		print("division: Division by zero\n");
		//check_zero(b);
		throw "Division by zero condition!";
   }
   return (a/b);
}

std::optional<double> division2(int a, int b)
{
   if( b == 0 ) 
   {
		print("division2: Division by zero\n");
		//throw "Division by zero condition!";
		return std::nullopt;
		//return {};
   }
   return (a/b);
}

	int x = 50;
	int y = 0;
	double z = 0;
 
	//z = division(x, y);

	try {
		z = division(x, y);
		print("{}\n", z);
	//} catch (const char* msg) {
		//print("{}\n", msg);
	} catch (...) {
	}
	q_print_sep_line();
	//#define runit(x) try { x } catch(...) {}

	auto res = division2(x, y);
	if (res) {
		print("{}\n", res.value());
	} else {
		print("Division by zero\n");
	}

//------------------
size_t next_pow2_usize(size_t v) 
{
    size_t i;

    static_assert(std::is_unsigned<size_t>::value, "Only works for unsigned types");
    v--;
    //Prefer size_t "Warning comparison between signed and unsigned integer"
    for (i = 1; i < (sizeof(v) * CHAR_BIT); i *= 2) 
    {
        v |= v >> i;

        //gout << i << qcs << v << sdf;
    }  

    // v >= (UINT64_MAX-1) do not increment, else 0 returned
    if (!(v >= (SIZE_MAX - 1)))
    {
        v++;
    }
    return v;
}

//---------------------------------------------------
//buffer allocating size and capacity in front
template<class T>
class buffer
{
public:
    T* m_data = nullptr;

    T* data() { return (m_data + sizeof(int64) + sizeof(int64)); }
    int64 length() { return scast<int>(*m_data); }
    void set_length(int64 length) { *m_data = length; }
    int64 capacity() { return scast<int>(*(m_data + sizeof(int64))); }
    void set_capacity(int64 capacity) { *(m_data + sizeof(int64)) = capacity; }

    const T& operator[] (isz i) const	    { return (m_data + sizeof(int64) + sizeof(int64))[i]; }
	T& operator[] (isz i)				    { return (m_data + sizeof(int64) + sizeof(int64))[i]; }

    void allocate(int64 num_elements)
    {
        m_data = scast<T*>(malloc(sizeof(int64) + sizeof(int64) + sizeof(T)*num_elements));
        set_length(num_elements);
        set_capacity(num_elements);
    }
};
//buffer<float> a;
//a.allocate(3);
//a[0] = 1.0f;
//println("{}, {}", a.length(), a.capacity());
//println("{}", a[0]);
#endif

//----------------------------------
// OpenGL pfd
// Get a hardware accelerated pixel format.
//PIXELFORMATDESCRIPTOR pfd =
//{
//	sizeof(PIXELFORMATDESCRIPTOR),
//	1,
//	PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
//	PFD_TYPE_RGBA,			// The kind of framebuffer. RGBA or palette. RGBA Format
//	32,						// Colordepth of the framebuffer: 32-bit RGBA color buffer. Color Depth
//	0, 0, 0, 0, 0, 0,
//	0,
//	0,
//	0,
//	0, 0, 0, 0,
//	24,						// Number of bits for the depthbuffer: 24-bit depth buffer. Z-Buffer (Depth Buffer)
//	8,						// Number of bits for the stencilbuffer: 8-bit stencil. Stencil buffer
//	0,						// Number of Aux buffers in the framebuffer.
//	PFD_MAIN_PLANE,			// Main Drawing Layer
//	0,
//	0, 0, 0
//};
//----------------------------------
#if 0
// string s = File.ReadAllText(filename);
// TextFileRead loads in a standard text file from a given filename and then returns it as a string.
bool read_text_all_methods(std::string& out_string, const char *file_name)
{
	//std::string out_string;

#if 0

	// Using getline
	// A string for holding the current line
	std::string line = std::string(); 

	// Open an input stream with the selected file
	std::ifstream filesrc_stream( file_name, std::ios::in ); 
	if (filesrc_stream.is_open()) 
	{
		// If the file opened successfully
		while (!filesrc_stream.eof()) 
		{ 
			// While we are not at the end of the file
			std::getline(filesrc_stream, line); // Get the current line
		  	out_string.append(line); // Append the line to our file string
			out_string.append("\n"); // Append a new line character
		}
		filesrc_stream.close(); // Close the file
	}
	else
	{
		//print("Cannot open input file: {}\n", file_name);
		return false;
	}


#else

	// Read the text from the file.
	// Open file.
	//std::ifstream filesrc_stream;
	//filesrc_stream.open(file_name);

	// Open file using constructor
	//std::ifstream filesrc_stream(file_name, std::ios::in);
	std::ifstream filesrc_stream(file_name, std::ios::in | std::ios::binary);

	//if (!filesrc_stream) { return false; }
	// Most vexing parse problem if () is removed surrounding 2nd parameter
	// TimeKeeper time_keeper(Timer()); is variable declaration or function declaration
	// programmer expect variable declaration but compiler interprets as function declaration
	//std::string out_string = std::string(std::istreambuf_iterator<char>(filesrc_stream), (std::istreambuf_iterator<char>()));
	// Uniform initialization syntax of C++11 solves Most vexing parse problem
	//std::string out_string{std::istreambuf_iterator<char>{filesrc_stream}, {}};
	//filesrc_stream.close();

	if (filesrc_stream.is_open())
	{
#if 1
		// fastest 
		filesrc_stream.seekg(0, std::ios::end);
        out_string.resize(filesrc_stream.tellg());
        filesrc_stream.seekg(0, std::ios::beg);
        filesrc_stream.read(&out_string[0], out_string.size());
        filesrc_stream.close();
#else
		// second fastest
		std::stringstream sstr;
		// Read file's buffer contents into streams.
		// Read file_name file stream in string stream. 
		sstr << filesrc_stream.rdbuf();		
		filesrc_stream.close();
		// Convert stream into string
		// Save string stream in std::string out_string
		out_string = sstr.str();

		// slowest
		//filesrc_stream.seekg(0, std::ios::end);
		//out_string.reserve(filesrc_stream.tellg());
		//filesrc_stream.seekg(0, std::ios::beg);
		//out_string.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

		//slow
		//filesrc_stream.seekg( 0, std::ios_base::end );
		//const std::streampos pos = filesrc_stream.tellg();
		//filesrc_stream.seekg(0, std::ios_base::beg);
		//if( pos!=std::streampos(-1) ) { out_string.reserve(static_cast<std::string::size_type>(pos)); }
		//out_string.assign(std::istream_iterator<char>(file), std::istream_iterator<char>());	
#endif
	}
	else
	{
		print("Cannot open input file: {}\n", file_name);
		return false;
	}

#endif

	//return(out_string);
	return true;
}

//=======================================================================
// cube tex coordinates are wrong
void fill_cube_rs_model_tut(rs_model& model)
{
	vertexnt_t cube_arr_vert_nt_d3d[] = {
		//front face
		{-1.0, -1.0, -1.0,	0.0, 0.0, -1.0,	0.0, 0.0},
		{-1.0,  1.0, -1.0, 0.0, 0.0, -1.0, 0.0, 1.0},
		{ 1.0,  1.0, -1.0, 0.0, 0.0, -1.0, 1.0, 1.0},
		{ 1.0, -1.0, -1.0, 0.0, 0.0, -1.0, 1.0, 0.0},
		//back face
		{-1.0, -1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0},
		{ 1.0, -1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0},
		{ 1.0,  1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0},
		{-1.0,  1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0},
		//top face
		{-1.0, 1.0, -1.0, 0.0, 1.0, 0.0, 0.0, 0.0},
		{-1.0, 1.0,  1.0, 0.0, 1.0, 0.0, 0.0, 1.0},
		{ 1.0, 1.0,  1.0, 0.0, 1.0, 0.0, 1.0, 1.0},
		{ 1.0, 1.0, -1.0, 0.0, 1.0, 0.0, 1.0, 0.0},
		//bottom face
		{-1.0, -1.0, -1.0, 0.0, -1.0, 0.0, 0.0, 0.0},
		{ 1.0, -1.0, -1.0, 0.0, -1.0, 0.0, 0.0, 1.0},
		{ 1.0, -1.0,  1.0, 0.0, -1.0, 0.0, 1.0, 1.0},
		{-1.0, -1.0,  1.0, 0.0, -1.0, 0.0, 1.0, 0.0},
		//left face
		{-1.0, -1.0,  1.0, -1.0, 0.0, 0.0, 0.0, 0.0},
		{-1.0,  1.0,  1.0, -1.0, 0.0, 0.0, 0.0, 1.0},
		{-1.0,  1.0, -1.0, -1.0, 0.0, 0.0, 1.0, 1.0},
		{-1.0, -1.0, -1.0, -1.0, 0.0, 0.0, 1.0, 0.0},
		//right face
		{ 1.0, -1.0, -1.0, 1.0, 0.0, 0.0, 0.0, 0.0},
		{ 1.0,  1.0, -1.0, 1.0, 0.0, 0.0, 0.0, 1.0},
		{ 1.0,  1.0,  1.0, 1.0, 0.0, 0.0, 1.0, 1.0},
		{ 1.0, -1.0,  1.0, 1.0, 0.0, 0.0, 1.0, 0.0},
	};

	uint cube_arr_indices_d3d[] = {
		//front face
		0, 1, 2,
		0, 2, 3,
		//back face
		4, 5, 6,
		4, 6, 7,
		//top face
		8, 9, 10,
		8, 10, 11,
		//bottom face
		12, 13, 14,
		12, 14, 15,
		//left face
		16, 17, 18,
		16, 18, 19,
		//right face
		20, 21, 22,
		20, 22, 23,
	};
	int64 cube_num_vertices = sdf::arr_cap(cube_arr_vert_nt_d3d);
	int64 cube_num_indices = sdf::arr_cap(cube_arr_indices_d3d);

	forloopi64(i, cube_num_vertices) {
		model.vertices.push_back(vertexf_from_vertexnt_t(cube_arr_vert_nt_d3d[i]));
	}
	forloopi64(i, cube_num_indices) {
		model.indices.push_back(cube_arr_indices_d3d[i]);
	}		
}
#endif