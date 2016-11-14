#!/usr/bin/env bats

@test "Message d'aide" {
    run bin/tp2 --help
    [ "$output" = 
    "Usage: bin/tp2 [--help] [--output-format FORMAT] [--output-filename FILENAME]
 [--show-languages] [--show-capital] [--show-borders] [--show-flag]
 [--country COUNTRY] [--region REGION]

Displays information about countries.

Optional arguments:
  --help                     Show this help message and exit.
  --output-format FORMAT     Selects the ouput format (either "text", "dot" or "png").
                             The "dot" format is the one recognized by Graphviz.
                             The default format is "text".
  --output-filename FILENAME The name of the output filename. This argument is
                             mandatory for the "png" format. For the "text" and "dot"
                             format, the result is printed on stdout if no output
                             filename is given.
  --show-languages           The official languages of each country are displayed.
  --show-capital             The capital of each country is displayed.
  --show-borders             The borders of each country is displayed.
  --show-flag                The flag of each country is displayed
                             (only for "dot" and "png" format).
  --country COUNTRY          The country code (e.g. "can", "usa") to be displayed.
  --region REGION            The region of the countries to be displayed.
                             The supported regions are "africa", "americas",
                             "asia", "europe" and "oceania"." ]
}

@test "Canada" {
    run --country can
    [ "$output" = 
    "Name: Canada
    Code: CAN" ]
}

@test "Canada, langues, capitale, frontieres" {
    run bin/tp2 --country can --show-languages --show-capital --show-borders
    [ "$output" = 
    "Name: Canada
    Code: CAN
    Capital: Ottawa
    Languages: English, French
    Borders: USA" ]
}

@test "Canada, langues, capitale, frontieres, drapeau, format dot" {
	run bin/tp2 --country can --show-languages --show-capital --show-borders \
	> --show-flag --output-format dot
	[ "$output" = 
	"graph {
    	can [
        	shape = none,
        	label = <<table border="0" cellspacing="0">
            	<tr><td align="center" border="1" fixedsize="true" width="200" height="100">
              	<img src="can.png" scale="true"/>
            	</td></tr>
            	<tr><td align="left" border="1"><b>Name</b>: Canada</td></tr>
            	<tr><td align="left" border="1"><b>Code</b>: CAN</td></tr>
            	<tr><td align="left" border="1"><b>Capital</b>: Ottawa</td></tr>
            	<tr><td align="left" border="1"><b>Language</b>: French, English</td></tr>
            	<tr><td align="left" border="1"><b>Borders</b>: USA</td></tr>
        	</table>>
    	];
	}" ] 
	
}	
