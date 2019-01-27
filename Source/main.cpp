/** @file start.cpp
 *  @section LICENSE
 *  @author  Wim Van Damme <wim.van_damme@alcatel-lucent.com>
 *  @brief Starting point of the model. Processes command line parameters and calls the according model/modules with the correct parameters.
 */

/** @mainpage CRAVE ASIC bit true C++ Model
*
* @author  Wim Van Damme <wim.van_damme@alcatel-lucent.com>
*
* @section intro Introduction
* This code has been developed in the context of the vectoring project. It represents a bit true software model of the data operations of the CRAVE ASIC, which will be present on future VP boards.
* The CRAVE comes in two variants. One calculates the corrections for 192 victims and 96 disturbers, the other for 96 victims and 192 disturbers.
* The simulated behavior consists of several tasks. The first is decompressing the crosstalk coefficients according to the input band configuration. The decompressed coefficients are then used in combination with the input tonedata to get the output corrections, per victim and per tone.
* Please refer to 3HH-13030-4001-DTZZA for the main sources of the software implementation.
*
* This VP model is called from a VC model developed by Carl Nuzman, John Lane Moss, and Adriaan De Lind Van Wijngaarden. This VC model extends the simulation to the other entities in the vectoring chain, allowing the combination of VP and VC model to predict the relative increase
* in performance that vectoring has to offer.
*
* @section repostruc Repo structure
*
* To get to the repository you need Mercurial and access to the central repo (see: https://acos.alcatel-lucent.com/wiki/g/isamsw/Using%20Mercurial%20In%20ISAM#Get_access_to_the_central_hg_serverx2e.) To get access from Cygwin you need to install Cygwin
* with development and net support (includes Mercurial, MinGW and ssh packages). You then need to copy the contents of the ~/.ssh map of your linux/unix distribution to the corresponding ~/.ssh directory in Cygwin. You should then be able to clone the repository.
*
* The repository is available from ssh://hg@hg.be.alcatel-lucent.com/all/crave_asic. The top folder contains following files:
* - Makefile_linux : makefile for linux, rename to Makefile and use make
* - Makefile_mingw : makefile for mingw under Cygwin, uses mingw g++ compiler in the Cygwin environment, rename to makefile and use make, compiling with mingw results in an executable that can be run on Windows and can be called by Matlab on windows
* - makefile-core : contains common makefile procedures
* - Doxyfile : contains the configuration for this doxygen documentation
*
* The top folder contains following folders:
* - src: contains all source files
* - build: created by makefile, contains the executable after compilation, as well as the object files
* - backup: created by makefile, contains a backup of the source files used for the last compilation
* - doc: contains the doxygen documentation, is created by running doxygen with the Doxyfile
*
* @section comp Compilation
*
* The model can be compiled for windows (mingw-gcc) or linux (gcc). This can be done by selecting the corresponding Makefile_x, renaming it to Makefile and using the make tool in either linux or cygwin respectively.
* Common make commands are:
* - make : compiles a debugging version of the model (slow)
* - make final : compiles an optimized release version of the model (fast)
* - make clean: cleans the repository, removes all object files and executables
*
* Note that when compiling for Windows and running the executable outside Cygwin, you may have to add the paths to the MinGW libraries (either from your Cygwin installation or a matching external installation) to your windows environment path variable. If you do not do this
* you will get missing .dll errors at runtime! The Cygwin MinGW .dll's can be found in C:/Cygwin/usr/i686-pc-mingw32/sys-root/mingw/bin.
*
* Also note that for compilation on a Linux platform the glog (google log) library is required. However, the usage of this library can be bypassed by setting the WIN32 flag.
* When compiling for windows using MinGW this flag is automatically set by the compiler. The easiest way to compile for windows is using Cygwin with Mercurial, ssh and MinGW support. Use Mercurial to pull the sources and compile with the MinGW Makefile. To run from outside Cygwin, you may have to add
* the path to the MinGW folder containing the MinGW .dlls to your windows environment path variable.
*
* For modeling the bit true behavior the algorithmic C datatypes (ac) library by Mentor Graphics has been used. This library consists solely of four header files (ac_int, ac_fixed, ac_complex and ac_sc) and is hence compiled with the executable. All types starting with ac are defined in these four header files. Usage of the library
* is permitted under the condition that no modifications are made to the library.
*
* @section usage Usage
*
* To learn about parameters and flags that can be passed on the command line, please execute the program without parameters to get a list of options. Interfacing with the model is done using regular text files. A regular run of the model requires an input tonedata text file, an input coefficients text file and an input configuration text file. It generates an output
* corrections text file. The details about these interfaces are described in 3FE-65055-1801-DTZZA. An example call looks as follows: craveASIC.exe –configfile <name> –coeffile <name> –tonedatafile <name> -correctionsfile <name>  -nLines <val> -nDisturbers <val> -nVictims <val>
*
* Aside from running the complete model (see launch_model.cpp) there is also the possibility of running several modules which cover only part of the VP chain. This is useful for verification that each part of the model is really a bit true representation of the hardware implementation.
* Please also refer to 3FE-65055-1801-DTZZA for module input and output interfaces. Modules are run by passing the corresponding command line flag and the described required parameters. Four modules have been defined:
* - Decompression module: see launch_decompression.cpp, converts input 5/5/2 (or 4/4/4) coefficients to decompressed 7/7/4 coefficients, for a single line and disturber pair.
* - Rounding module: see launch_rounding.cpp, converts 28/28 input to 6/6/4 format
* - Single line 96 disturbers 5/5/2 input: see launch_single96dist_552.cpp, decompresses and executes the processing line stage up to the point before rounding.
* - Single line 96 disturbers 7/7/4 input: see launch_single96dist_774.cpp,bypasses the decompression step and takes decompressed coefficients from a text file as input. Then executes up to the point before rounding.
*
* @section description Description
*
* This section contains a short overview of how the code works. In the file start.cpp the command line arguments are processed. Depending on these
* either a module or the complete model is launched. Each of these has a launch_x file that contains the function that executes it. In these functions
* first the input files are read and memory is allocated. Then the model or module is executed and the output is written. Afterwards memory is freed again.
*
* The main functionality model is centered around three important classes.
* - The first is the MME class. This class manages Mantissa-Mantissa-Exponent data. It uses the
* algorithmic C (ac) library to support custom bit widths. For more information about this library refer to http://www.mentor.com/esl/catapult/algorithmic. Real and imaginary mantissas and
* the exponent are all defined using an ac type. Important to realize about the library is that assignment between ints and custom bitwidth types, and in between custom bitwidths is fully overloaded, but the behavior is very strictly defined in the documentation.
* The class allows one to generically load MME values from compacted ushorts or simply seperate values, for any bitwidths. It also allows one to
* display the loaded numbers in binary or decimal formats and access each datafield separately. In the Decompression and the PLS typically an MME instance is predefined for each intermediate value, with
* the bitwidths of that intermediate value. The data is then processed and forwarded from type to type. When loading data in a type the bitwidth conversion is automatically done, based on the type definition. All the used types are listed in the corresponding PLS_types.h or Decompression_types.h file. If you want to get an overview of which bitwidths are used where, these are the files to look at.
* - The second important class is the Decompression class. This class implements the decompression of 5/5/2 (or 4/4/4) coefficients into 7/7/4 coefficients. The decompression is done
* on a per victim basis. Memory is allocated for only one victim, so after a victim is decompressed it is processed in the PLS stage before decompressing a next victim. This allows to reuse the memory
* assigned for storing the decompressed coefficients. The decompression class consists of two important functions, the first is simply called decompress. It will
* treat the first tonegroup in a band separately from the others because this one may or may not have a bandstart, depending on the band configuration. If it has a bandstart the number
* has to be loaded as 4/4/4, if not as 5/5/2. The other tonegroups are then processed in a loop. Each tonegroup is processed by calling decompressStep a number of times equal to the decimation factor defined for the band.
* The decompressed coefficients are stored in memory. More information about the decompression internals can be found in 3HH-13030-4001-DTZZA.
* - The third important class is the PLS class. This class implements the processing line stage and converts tonedata (6/6/4) and coefficients (7/7/4) in 28/28 bit corrections. This is done
* on a per victim and per tone basis. The PLS class contains the same building blocks as the hardware (see 3HH-13030-4001-DTZZA). This means it also processes disturbers 6 by 6, i.e. per victim and per tone an iteration over all disturbers
* is required.
*/

#include "common.h"
#include "launch_model.h"
#include <assert.h>

using namespace std;

//global variables, only for flags
extern bool Wdecomp = false;
//extern bool Wround = false;



int main(int argc, char* argv[]) {

	int i = 0 ;

	/*default values*/
	int nVictims = 16;
	int nDisturbers = 48;
	int nLines = 48;
	char* configFile = "configuration.txt";
	char* coefFile = "coefficients.txt";
	char* tonedataFile = "tonedata.txt";
	char* correctionsFile = "corrections_121244_single_line_out.txt";
	char* verboseOutputDir = "corrections_121244_single_line_out.txt";

	string mode = "main";

	/*load command line values*/
	if( argc == 1 )
	{
		cout << "Usage:" << endl << endl;
		cout << "-nLines <value> " << endl << "number of lines, default: 384" << endl<< endl;
		cout << "-nVictims <value> " << endl << "number of victims, default: 192" << endl << endl;
		cout << "-nDisturbers <value> " << endl << "number of disturbers, default: 96" << endl<< endl;
		cout << "-configfile <name> " << endl << "name of the configuration file to be used" << endl<< endl;
		cout << "-coeffile <name> " << endl << "name of the coefficients file to be used" << endl<< endl;
		cout << "-tonedatafile <name> " << endl << "name of the tonedata file to be used" << endl<< endl;
		cout << "-correctionsfile <name> " << endl << "name of the corrections output file to be used" << endl<< endl;
		cout << "-verboseoutputdir <name> " << endl << "optional directory path where intermediate files will be written" << endl<< endl;
		return 0;
	}

	for( i = 1; i < argc; i++ )
	{
		if( !strcmp( argv[i], "-nVictims" ) )
		{
			nVictims = atoi( argv[++i] );
		}
		else if( !strcmp( argv[i], "-nDisturbers" ) )
		{
			nDisturbers = atoi( argv[++i] );
		}
		else if( !strcmp( argv[i], "-nLines" ) )
		{
			nLines = atoi( argv[++i] );
		}
		else if( !strcmp( argv[i], "-configfile" ) )
		{
			configFile = argv[++i];
		}
		else if( !strcmp( argv[i], "-coeffile" ) )
		{
			coefFile = argv[++i];
		}
		else if( !strcmp( argv[i], "-tonedatafile" ) )
		{
			tonedataFile = argv[++i];
		}
		else if ( !strcmp( argv[i], "-correctionsfile" ) ){
			correctionsFile = argv[++i];
		}
		else if ( !strcmp( argv[i], "-verboseoutputdir" ) ){
			verboseOutputDir = argv[++i];
		}
	}

	/*print resulting values*/

	LOGM(INFO,"Using parameters: ")
	LOGM(INFO,"\t configuration file: " << configFile)
	LOGM(INFO,"\t coefficients file: " << coefFile)
	LOGM(INFO,"\t tonedata file: " << tonedataFile)
	LOGM(INFO,"\t number of lines: " << nLines)
	LOGM(INFO,"\t number of victims: " << nVictims)
	LOGM(INFO,"\t number of disturbers: " << nDisturbers)

	/* launch the simulation model*/
	if (mode == "main"){
		launch_model(configFile,coefFile,tonedataFile,correctionsFile,nVictims, nDisturbers, nLines, verboseOutputDir);
	}

	return 0;
}
