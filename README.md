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

save before build
Window --> Preferences --> General --> Workspace
on this page, select the Save automatically before build

