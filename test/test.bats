#!/usr/bin/env bats

#@test "Message d'aide" {
#    run bin/tp2 --help
#    [ "$output" =  
#    "Usage: bin/tp2 [--help] [--output-format FORMAT] [--output-filename FILENAME]
# [--show-languages] [--show-capital] [--show-borders] [--show-flag]
# [--country COUNTRY] [--region REGION]
#
#Displays information about countries.
#
#Optional arguments:
#  --help                     Show this help message and exit.
#  --output-format FORMAT     Selects the ouput format (either "text", "dot" or "png").
#                             The "dot" format is the one recognized by Graphviz.
#                             The default format is "text".
#  --output-filename FILENAME The name of the output filename. This argument is
#                             mandatory for the "png" format. For the "text" and "dot"
#                             format, the result is printed on stdout if no output
#                             filename is given.
#  --show-languages           The official languages of each country are displayed.
#  --show-capital             The capital of each country is displayed.
#  --show-borders             The borders of each country is displayed.
#  --show-flag                The flag of each country is displayed
#                             (only for "dot" and "png" format).
#  --country COUNTRY          The country code (e.g. "can", "usa") to be displayed.
#  --region REGION            The region of the countries to be displayed.
#                             The supported regions are "africa", "americas",
#                             "asia", "europe" and "oceania"." ]
#}

@test "Canada" {
    run ~/inf3135-aut2016-tp2/bin/tp2 --country can
   
    [ "${lines[0]}" = "Name: Canada" ]
    [ "${lines[1]}" = "Code: CAN" ]
}

@test "Canada, langues, capitale, frontieres" {
    run ~/inf3135-aut2016-tp2/bin/tp2 --country can --show-languages --show-capital --show-borders

    [ "${lines[0]}" = "Name: Canada" ]
    [ "${lines[1]}" = "Code: CAN" ]
    [ "${lines[2]}" = "Capital: Ottawa" ]
    [ "${lines[3]}" = "Languages: English, French" ]
    [ "${lines[4]}" = "Borders: USA" ]
}

@test "Canada, langues, capitale, frontieres, drapeau, format dot" {
	run ~/inf3135-aut2016-tp2/bin/tp2 --country can --show-languages --show-capital --show-borders --show-flag --output-format dot
    
    [ "${lines[0]}" = "graph {" ]
    [ "${lines[1]}" = "    CAN [" ]
    [ "${lines[2]}" = "        shape = none" ]
    [ "${lines[3]}" = "        label = <<table border=\"0\" cellspacing=\"0\">" ]
    [ "${lines[4]}" = "            <tr><td align=\"center\" border=\"1\" fixedsize=\"true\" width=\"200\" height=\"100\"><img src=\"data/countries/data/can.png\" scale=\"true\"/></td></tr>" ]
    [ "${lines[5]}" = "            <tr><td align=\"left\" border=\"1\"><b>Name</b>: Canada</td></tr>" ]
    [ "${lines[6]}" = "            <tr><td align=\"left\" border=\"1\"><b>Code</b>: CAN</td></tr>" ]
    [ "${lines[7]}" = "            <tr><td align=\"left\" border=\"1\"><b>Capital</b>: Ottawa</td></tr>" ]
    [ "${lines[8]}" = "            <tr><td align=\"left\" border=\"1\"><b>Language</b>: English, French</td></tr>" ]
    [ "${lines[9]}" = "            <tr><td align=\"left\" border=\"1\"><b>Borders</b>: USA</td></tr>" ]
    [ "${lines[10]}" = "        </table>>" ]
    [ "${lines[11]}" = "    ];" ]
    [ "${lines[12]}" = "}" ]
	
}	
