/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Dvir Benita
 * 
 * Date: 2020-02
 */

#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;



TEST_CASE("Test replacement of p and b") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    /* Add more checks here */
}
TEST_CASE("Test replacement of v and w"){
    string text = "ovoviviparously xxxxx";
    CHECK(find(text,"ovoviviparously") == string("ovoviviparously"));
    CHECK(find(text,"owoviviparously") == string("ovoviviparously"));
    CHECK(find(text,"ovowiviparously") == string("ovoviviparously"));
    CHECK(find(text,"ovoviwiparously") == string("ovoviviparously"));
    CHECK(find(text,"owowiviparously") == string("ovoviviparously"));
    CHECK(find(text,"owowiwiparously") == string("ovoviviparously"));
    CHECK(find(text,"ovowiwiparously") == string("ovoviviparously"));
    CHECK(find(text,"owoviviparously") == string("ovoviviparously"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text1 = "Happi xxx yyy";
    CHECK(find(text1, "happi") == string("Happi"));
    CHECK(find(text1, "Happi") == string("Happi"));
    CHECK(find(text1, "HAPPI") == string("Happi"));
    CHECK(find(text1, "HaPpI") == string("Happi"));
    string text = "ovoviviparously xxxxx";
    CHECK(find(text,"oVoViViparously") == string("ovoviviparously"));
    CHECK(find(text,"Ovoviviparously") == string("ovoviviparously"));
    CHECK(find(text,"oVoviviparously") == string("ovoviviparously"));
    CHECK(find(text,"ovOviviparously") == string("ovoviviparously"));
    CHECK(find(text,"ovoViviparously") == string("ovoviviparously"));
    CHECK(find(text,"ovovIviparously") == string("ovoviviparously"));
    CHECK(find(text,"ovoviViparously") == string("ovoviviparously"));
    CHECK(find(text,"ovovivIparously") == string("ovoviviparously"));
    CHECK(find(text,"ovoviviParously") == string("ovoviviparously"));
    CHECK(find(text,"ovovivipArously") == string("ovoviviparously"));
    CHECK(find(text,"ovovivipaRously") == string("ovoviviparously"));
    CHECK(find(text,"ovoviviparOusly") == string("ovoviviparously"));
    CHECK(find(text,"ovoviviparoUsly") == string("ovoviviparously"));
    CHECK(find(text,"ovoviviparouSly") == string("ovoviviparously"));
    CHECK(find(text,"ovoviviparouslY") == string("ovoviviparously"));
    CHECK(find(text,"ovoviviparousLy") == string("ovoviviparously"));

    
}

TEST_CASE("Repalcement f and p"){
    string text = "happy xxx";

    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "haffy") == string("happy"));
    CHECK(find(text, "hapfy") == string("happy"));
    CHECK(find(text, "hafpy") == string("happy"));
}




TEST_CASE("The word not exsist"){
    string text = "fuck you";
    CHECK_THROWS_AS(find(text,"dog"),exception);
}

TEST_CASE("The empty word"){
    string text = "aba xxx";
    CHECK_THROWS_AS(find(text,""),exception);
}

TEST_CASE("Not one word"){
    string text = "aba xxx";
    CHECK_THROWS_AS(find(text,"aba xxx"),exception);
}





TEST_CASE("Test replacement of c and k") // 10 tests
{
    string wordFromText = "back";
    string text = "never look " + wordFromText;

    //lower-case
    CHECK(find(text, "back") == string(wordFromText));
    CHECK(find(text, "bakk") == string(wordFromText));
    CHECK(find(text, "bacc") == string(wordFromText));
    CHECK(find(text, "bakc") == string(wordFromText));

    //upper-case
    CHECK(find(text, "Back") == string(wordFromText));
    CHECK(find(text, "baKK") == string(wordFromText));
    CHECK(find(text, "baCC") == string(wordFromText));
    CHECK(find(text, "baKc") == string(wordFromText));

    //throw - word isn't in the sentence
    CHECK_THROWS_AS(find(text, "bac"), std::exception);
    CHECK_THROWS_AS(find(text, "bak"), std::exception);
}


TEST_CASE("Test replacement of k and q") // 10 tests
{
    string wordFromText = "quick";
    string text = "come here, " + wordFromText;

    //lower-case
    CHECK(find(text, "quick") == string(wordFromText));
    CHECK(find(text, "kuick") == string(wordFromText));
    CHECK(find(text, "quicq") == string(wordFromText));
    CHECK(find(text, "kuicq") == string(wordFromText));

    //upper-case
    CHECK(find(text, "Quick") == string(wordFromText));
    CHECK(find(text, "Kuick") == string(wordFromText));
    CHECK(find(text, "quicQ") == string(wordFromText));
    CHECK(find(text, "kuicQ") == string(wordFromText));

    //throw - word isn't in the sentence
    CHECK_THROWS_AS(find(text, "quic"), std::exception);
    CHECK_THROWS_AS(find(text, "kuic"), std::exception);
}

TEST_CASE("Test replacement of s and z") // 5 tests
{
    string wordFromText = "famous";
    string text = "a " + wordFromText + " actor";

    //lower-case
    CHECK(find(text, "famous") == string(wordFromText));
    CHECK(find(text, "famouz") == string(wordFromText));

    //upper-case
    CHECK(find(text, "Famous") == string(wordFromText));
    CHECK(find(text, "Famous") == string(wordFromText));

    //throw - word isn't in the sentence
    CHECK_THROWS_AS(find(text, "famou"), std::exception);
}


TEST_CASE("Test replacement of s and z") // 5 tests
{
    string wordFromText = "small";
    string text = "Here is a " + wordFromText + " harbour";

    //lower-case
    CHECK(find(text, "small") == string(wordFromText));
    CHECK(find(text, "zmall") == string(wordFromText));

    //upper-case
    CHECK(find(text, "Small") == string(wordFromText));
    CHECK(find(text, "Zmall") == string(wordFromText));

    //throw - word isn't in the sentence
    CHECK_THROWS_AS(find(text, "smal"), std::exception);
}


TEST_CASE("Test replacement of d and t") // 10 tests
{
    string wordFromText = "detective";
    string text = "The " + wordFromText + " examined the window frame for fingerprints";

    //lower-case
    CHECK(find(text, "detective") == string(wordFromText));
    CHECK(find(text, "tetective") == string(wordFromText));
    CHECK(find(text, "dedective") == string(wordFromText));
    CHECK(find(text, "detecdive") == string(wordFromText));

    //upper-case
    CHECK(find(text, "Detective") == string(wordFromText));
    CHECK(find(text, "tetecTive") == string(wordFromText));
    CHECK(find(text, "deDective") == string(wordFromText));
    CHECK(find(text, "detecDive") == string(wordFromText));

    //throw - word isn't in the sentence
    CHECK_THROWS_AS(find(text, "detecti"), std::exception);
    CHECK_THROWS_AS(find(text, "detectiv"), std::exception);
}

TEST_CASE("Mix of Test replacement") // 10 tests
{
    string text = "Dond vorri be haffy";

    //lower-case
    CHECK(find(text, "dont") == string("Dond"));
    CHECK(find(text, "worry") == string("vorri"));
    CHECK(find(text, "be") == string("be"));
    CHECK(find(text, "happy") == string("haffy"));

    //upper-case
    CHECK(find(text, "DONT") == string("Dond"));
    CHECK(find(text, "woRRy") == string("vorri"));
    CHECK(find(text, "BE") == string("be"));
    CHECK(find(text, "Happy") == string("haffy"));

    //throw - word isn't in the sentence
    CHECK_THROWS_AS(find(text, "don"), std::exception);
    CHECK_THROWS_AS(find(text, "happ"), std::exception);
}

TEST_CASE("Mix of Test replacement") // 10 tests
{
    string text = "harri putter and the corsed child";

    //lower-case
    CHECK(find(text, "harry") == string("harri"));
    CHECK(find(text, "potter") == string("putter"));
    CHECK(find(text, "and") == string("and"));
    CHECK(find(text, "cursed") == string("corsed"));

    //upper-case
    CHECK(find(text, "HarrY") == string("harri"));
    CHECK(find(text, "POTTER") == string("putter"));
    CHECK(find(text, "AnD") == string("and"));
    CHECK(find(text, "CURsed") == string("corsed"));

    //throw - word isn't in the sentence
    CHECK_THROWS_AS(find(text, "potte"), std::exception);
    CHECK_THROWS_AS(find(text, "harr"), std::exception);
}
