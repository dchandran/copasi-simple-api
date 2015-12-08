## A Simple API for COPASI ##

This code is a C interface to the Copasi C++ library. This library can be used to read and write Systems Biology Markup Language (SBML) files and simulate them using deterministic or stochastic simulation. Additional analysis, such as computing eigenvalues and steady states, can also be performed. The models can also be constructed using C function calls such as cCreateSpecies(...) and cCreateReaction(...). Antimony scripts can also be used to load models. The structural library is also included within this library for analyzing the stoichiometry matrix. See the API documentation for the list of all available functions.

This work was funded by subcontract NIGMS grant: GM076692 from James Glazier, Indiana University.

Two APIs are provided:

1. Suited to using with scripting languages using SWIG

2. SBW Api which is the standard API used by SBW and is suited to using with compiled applications. This API is also compatible with the roadRunner API.

[Copasi\_API Documentation](http://copasi-simple-api.googlecode.com/svn/trunk/documentation/html/copasi__api_8h.html)

[Example code](http://code.google.com/p/copasi-simple-api/source/browse/trunk/testSuite/testBasicAPI.c)

## How to get the source code ##

First, install Subversion. In Linux and Mac, just use apt-get svn.
In Windows, download and install either TortoiseSVN (graphical version) or SilkSVN (command-line version).

Once Subversion is installed, use the following command to get the source:
svn checkout https://copasi-simple-api.googlecode.com/svn/trunk/

If you are using TortoiseSVN, first create an empty folder called copasi-api. Then
right-click on that newly created folder and select "SVN Checkout". Enter
https://copasi-simple-api.googlecode.com/svn/trunk/ as the URL for repository.

## Binaries ##

Binaries (including dependencies and example exe) for Windows are available from the [downloads page](http://code.google.com/p/copasi-simple-api/downloads/list) in the form of a zip file.


## How to build the library on Windows, Linux and Mac ##

The initial phase of the build process is the same for each platform, that is installing CMake and generating the appropriate build files, e.g. sln files for Visual Studio, make files for Linux and Mac.

Lets assume that the source code is located in a folder named "copasi-simple-api"

1) (Windows only) If you want to compile the source on without using Visual Studio you should download MinGW from www.mingGW.org. Download the GUI installer it will be easier to use (https://sourceforge.net/projects/mingw/files/Automated%20MinGW%20Installer/mingw-get-inst/).

2) Install Cmake from cmake.org
> for Linux, just type 'apt-get cmake cmake-gui'

3) Run cmake-gui
> In the Cmake program, find two text boxes labeled, "where is the source code" and "where to build"

3) Type the full copasi-simple-api/ folder path for the line that says "where is the source code"

4) Type copasi-simple-api/BUILD folder path for the line that says "where to build"

5) Click the "Configure" button. At this point a number of errors might emerge, this can include:

6) If you have MinGW installed make sure you choose to generate the MinGW makefiles!

7) You may have problems if other gcc compilers are currently installed, eg Maxima comes with its own gcc and so does pythonxy. You will need to remove these if this is the case.

8) The other issues that can happen is if you have other development environments installed, cmake can get confused, for example it could locate the non-minGW make application. If this is the case edit the CMakeCache.txt file located in BUILD.


9) Cmake will create the BUILD folder and then ask you to select the compiler.
> It is recommended that you use standard compilers, e.g. gcc for Unix and
> Visual Studio or MinGW for MS Windows. Pick the MinGW Makefiles for MinGW.

> Make sure **that the ENABLE\_LAYOUT option is turned on**, as it is required by Copasi

10) Once configuration is done, click the "Generate" button

11) Go to the copasi-simple-api/BUILD folder.

> If you used Visual Studio as the compiler, you will find a project file (.sln) -- open it. Find the copasi\_api\_test, right-click on it, and set it as the startup project.

> If you used GCC or MinGW, "cd" into the BUILD folder and run "make copasi\_api\_test"

12) Run copasi\_api\_test
> This was an example code using the copasi API. Now you can replace copasi\_api\_test with your own program.

**NOTE: Visual Studio** has some complications with the boost regular expression library that is used in this project. No need to worry. CMake will take care of the problem as long as you set the CMAKE\_BUILD\_TYPE variable in the Cmake GUI to either "Debug" or "Release", depending on what type of project you will be building.

**NOTE: Windows** When using the 32-bit binaries on Windows make sure you have the Microsoft Visual C++ 2010 Redistributable Package (x86)on your system which can be obtained from http://www.microsoft.com/download/en/details.aspx?id=5555

During compilation, each file in the testSuite folder will generate an executable file.

## Generating or updating the Documentation ##

The documentation is automatically generated using the comments in the copasi\_api.h file. To change the documentation, you just need to edit that file. To generate the new documentation, follow these steps:

1) Download and install Doxygen from
> http://www.stack.nl/~dimitri/doxygen/download.html#latestsrc

2) Run Doxygen wizard (the executable is usually called doxywizard)

3) In the Doxygen window, enter "Copasi API" as the project name, and provide a version number. Set the copasi-simple-api folder as the source folder and copasi-simple-api/documentation as the destination folder. At the top of the window, specify the working directory as the copasi-simple-api/documentation folder.

4) Click Next. Select "Optimize for C" in the the programming languages option

5) Click Next a few times until you reach the end. At the top of the window

6) Go to the "Run" tab and click "Run doxygen".

7) The documentation has been generated. Use svn commit on the copasi-simple-api/documentation folder to update the online documentation.

8) Tip: You might find that a new html file generated from doxygen does not render in
the browser. In order to make the html render correctly, make sure you add the text/html mime type to the file. Under TortoiseSVN, select the file and choose properties from the
TortoiseSVN popup menu. Select svn:mime-type in the property type and add text/html to the property value. Select OK and commit the change. The html file will now render correctly.

Alternatively you can make SVN do this for you by editing the SVN configuration file. To do this, select Settings under TortoiseSVN. In the general tab (usually the first you'll see) there is a button marked Edit towards the right hand corner, select this and the config file will be loaded into your favourite editor. In the config file locate the line, [miscellany](miscellany.md) and uncomment the line marked: enable-auto-props = yes. Finally, locate the line [auto-props] and add the following lines to the end of section:

```
*.html = svn:mime-type=text/html
*.css = svn:mime-type=text/css
*.js = svn:mime-type=text/javascript
*.txt = svn:mime-type=text/plain;svn:eol-style=native
*.png = svn:mime-type=image/png
*.jpg = svn:mime-type=image/jpeg
*.pdf = svn:mime-type=application/pdf
*.jpeg = svn:mime-type=image/jpg
*.tiff = svn:mime-type=image/tiff
*.tif = svn:mime-type=image/tiff
```