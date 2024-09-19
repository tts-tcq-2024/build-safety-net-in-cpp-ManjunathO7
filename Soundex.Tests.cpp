#include <gtest/gtest.h>
#include "Soundex.h"


#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTest, BasicTest) {
    EXPECT_EQ(generateSoundex("Harish"), "H620");
    EXPECT_EQ(generateSoundex("Kumar"), "K560");
    EXPECT_EQ(generateSoundex("Shibashis"), "S120");
    EXPECT_EQ(generateSoundex("Manjunath"), "M525");
    EXPECT_EQ(generateSoundex("Nagaraj"), "N262");
}

TEST(SoundexTest, EdgeCases) {
    EXPECT_EQ(generateSoundex("Chand"), "C530");
    EXPECT_EQ(generateSoundex("Mehra"), "M600");
    EXPECT_EQ(generateSoundex("Pandey"), "P530");
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, CaseInsensitive) {
    EXPECT_EQ(generateSoundex("MANJUNATH"), "M525");
    EXPECT_EQ(generateSoundex("NAgAraJ"), "N262");
    EXPECT_EQ(generateSoundex("ShibASHis"), "S120");
}

TEST(SoundexTest, SingleCharacterName) {
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("B"), "B000");
}

TEST(SoundexTest, AllVowels) {
    EXPECT_EQ(generateSoundex("Aeio"), "A000");
    EXPECT_EQ(generateSoundex("Euio"), "E000");
}
