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
