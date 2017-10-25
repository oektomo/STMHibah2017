create bin
Project --> Properties --> C/C++ Build --> Settings
tab "Tool Settings" Cross ARM GNU Create Flash Image collapse and select General
on this page select "Raw binary" in Output file format

create st-flash configuration
Run --> External Tools --> External Tools Configurations
create new, name it as "ST-Flash"

in location: /usr/local/bin/st-flash
in working directory: ${project_loc}/Release/ 
in Arguments: write ${project_name}.bin 0x8000000

Save before build
Window --> Preferences --> General --> Workspace
on this page, select the Save automatically before build

To include source file
Project --> Properties --> C/C++ General --> Paths and Symbols
on this page select tab Source Location and Edit filter

Remove:
-stm32f10x_uart.c

To do:
make a header

