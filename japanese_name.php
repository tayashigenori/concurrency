<?php

function katakanaToKanji($katakana_en)
{
    preg_match("/コ|レ/", $katakana_en, $matches);
    if ($matches[0] == "コ") return "並行";
    if ($matches[0] == "レ") return "並列";
    return "no match";
}
function alphabetToKanji($alph_en)
{
    preg_match("/c|r/i", $alph_en, $matches);
    if (in_array($matches[0], array("c", "C"))) return "並行";
    if (in_array($matches[0], array("r", "R"))) return "並列";
    return "no match";
}

echo alphabetToKanji("Parallel")."\n";
echo alphabetToKanji("Concurrent")."\n";

echo katakanaToKanji("パラレル")."\n";
echo katakanaToKanji("コンカレント")."\n";
