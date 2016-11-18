#!/usr/bin/env bats

@test "Pays valide" {
    run ./bin/tp2 --country can
    [ "${lines[0]}" = "Name: Canada" ]
    [ "${lines[1]}" = "Code: CAN" ]
}

@test "Canada" {
    run ./bin/tp2 --country can
   
    [ "${lines[0]}" = "Name: Canada" ]
    [ "${lines[1]}" = "Code: CAN" ]
}

@test "Canada, langues, capitale, frontieres" {
    run ./bin/tp2 --country can --show-languages --show-capital --show-borders --show-flag

    [ "${lines[0]}" = "Name: Canada" ]
    [ "${lines[1]}" = "Code: CAN" ]
    [ "${lines[2]}" = "Capital: Ottawa" ]
    [ "${lines[3]}" = "Languages: English, French" ]
    [ "${lines[4]}" = "Borders: USA" ]
}

@test "Canada, langues, capitale, frontieres, drapeau, format dot" {
	run ./bin/tp2 --country can --show-languages --show-capital --show-borders --show-flag --output-format dot
    
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

@test "Canada, langues, capitale, frontieres, drapeau, fichier dot" {
	run ./bin/tp2 --country can --show-languages --show-capital --show-borders --output-format dot --output-filename test.dot
    [ "$output" = "" ]
    rm test.dot
}

@test "Output-filename aucun nom donné" {
	run ./bin/tp2 --country can --show-languages --show-capital --show-borders --output-format dot --output-filename 
    [ "${lines[0]}" = "/home/jean-lou/INF3135/tp2/inf3135-aut2016-tp2/bin/tp2: option '--output-f       ormat' requires an argument" ]
    [ "${lines[1]}" = "Try using 'bin/tp2 --help' for more information." ]
}

@test "Option inexistante" {
    run ./bin/tp2 --country can --show-languages --show-capital --show-borders --show-hello
    [ "${lines[0]}" = "/home/jean-lou/INF3135/tp2/inf3135-aut2016-tp2/bin/tp2: unrecognized optio       n '--show-hello' " ]
    [ "${lines[1]}" = "Try Using 'bin/tp2' --help        for more information " ]
}
