#!/usr/bin/env bats

@test "Pays valide" {
    run ./bin/tp2 --country brn
    [ "${lines[0]}" = "Name: Nation of Brunei, Abode of Peace" ]
    [ "${lines[1]}" = "Code: BRN" ]
}

@test "Nation of Brunei, langues, capitale, frontieres" {
    run ./bin/tp2 --country brn --show-languages --show-capital --show-borders --show-flag

    [ "${lines[0]}" = "Name: Nation of Brunei, Abode of Peace" ]
    [ "${lines[1]}" = "Code: BRN" ]
    [ "${lines[2]}" = "Capital: Bandar Seri Begawan" ]
    [ "${lines[3]}" = "Languages: Malay" ]
    [ "${lines[4]}" = "Borders: MYS" ]
}

@test "Nation of Brunei, langues, capitale, frontieres, drapeau, format dot" {
	run ./bin/tp2 --country brn --show-languages --show-capital --show-borders --show-flag --output-format dot
    
    [ "${lines[0]}" = "graph {" ]
    [ "${lines[1]}" = "    BRN [" ]
    [ "${lines[2]}" = "        shape = none" ]
    [ "${lines[3]}" = "        label = <<table border=\"0\" cellspacing=\"0\">" ]
    [ "${lines[4]}" = "            <tr><td align=\"center\" border=\"1\" fixedsize=\"true\" width=\"200\" height=\"100\"><img src=\"data/countries/data/brn.png\" scale=\"true\"/></td></tr>" ]
    [ "${lines[5]}" = "            <tr><td align=\"left\" border=\"1\"><b>Name</b>: Nation of Brunei, Abode of Peace</td></tr>" ]
    [ "${lines[6]}" = "            <tr><td align=\"left\" border=\"1\"><b>Code</b>: BRN</td></tr>" ]
    [ "${lines[7]}" = "            <tr><td align=\"left\" border=\"1\"><b>Capital</b>: Bandar Seri Begawan</td></tr>" ]
    [ "${lines[8]}" = "            <tr><td align=\"left\" border=\"1\"><b>Language</b>: Malay</td></tr>" ]
    [ "${lines[9]}" = "            <tr><td align=\"left\" border=\"1\"><b>Borders</b>: MYS</td></tr>" ]
    [ "${lines[10]}" = "        </table>>" ]
    [ "${lines[11]}" = "    ];" ]
    [ "${lines[12]}" = "}" ]
}

@test "Nation of Brunei, langues, capitale, frontieres, drapeau, fichier dot" {
	run ./bin/tp2 --country brn --show-languages --show-capital --show-borders --output-format dot --output-filename test.dot
    [ "$output" = "" ]
    rm test.dot
}

@test "Nation of Brunei, langues, capitale, frontieres, drapeau, fichier txt" {
	run ./bin/tp2 --country brn --show-languages --show-capital --show-borders --output-format text --output-filename test.txt
    [ "$output" = "" ]
    rm test.txt
}


@test "Option '--output-filename' sans argument" {
	run ./bin/tp2 --country brn --show-languages --show-capital --show-borders --output-format dot --output-filename 
    [ "${lines[0]}" = "./bin/tp2: option '--output-filename' requires an argument" ]
    [ "${lines[1]}" = "Try using 'bin/tp2 --help' for more information." ]
}

@test "Option inexistante" {
    run ./bin/tp2 --country brn --show-languages --show-capital --show-borders --show-hello
    [ "${lines[0]}" = "./bin/tp2: unrecognized option '--show-hello'" ]
    [ "${lines[1]}" = "Try using 'bin/tp2 --help' for more information." ]
}

@test "Message d'aide" {
    run ./bin/tp2 --country brn --show-borders --help
    [ "${lines[0]}" = "Usage: bin/tp2 [--help] [--output-format FORMAT] [--output-filename FILENAME]" ]
}

@test "Code pays inexistant" {
    run ./bin/tp2 --country hello --show-borders --show-languages
    [ "${lines[0]}" = "Invalid country code." ]
}

@test "Region inexistante" {
    run ./bin/tp2 --region hello --show-borders --show-languages
    [ "${lines[0]}" = "Invalid region." ]
}


@test "Format 'png' sans nom." {
    run ./bin/tp2 --country brn --output-format png --show-flag 
    [ "${lines[0]}" = "Filename required for 'png' format." ]
}

@test "Format 'text' sans '--output-filename'" {
    run ./bin/tp2 --country brn --output-format text --show-flag 
    [ "${lines[0]}" = "Name: Nation of Brunei, Abode of Peace" ]
	[ "${lines[1]}" = "Code: BRN" ]
}
@test "Format de fichier non reconnu" {
    run ./bin/tp2 --country brn --output-format hello --show-flag 
    [ "${lines[0]}" = "Invalid file format." ]
}

@test "Region et country activées" {
    run ./bin/tp2 --country brn --region Europe  
    [ "${lines[0]}" = "Name: Nation of Brunei, Abode of Peace" ]
    [ "${lines[1]}" = "Code: BRN" ]
    [ "${lines[2]}" = "Option '--country' activated; option '--region' ignored." ]
}

