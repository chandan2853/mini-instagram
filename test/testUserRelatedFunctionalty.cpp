#include "../src/user.cpp"
#include "./gtest/gtest.h"

TEST(validPassword, checkingPasswordWhichContsainOnlyIntegerValue_givesFalse)
{
    bool result = UserUtility::validPassword("1262545236");
    ASSERT_EQ(result, false);
}
TEST(validPassword, checkingPasswordWhichContsainOnlyCharacterValue_givesFalse)
{
    bool result = UserUtility::validPassword("hdsjhKJGF");
    ASSERT_EQ(result, false);
}
TEST(validPassword, checkingPasswordWhoseLengthLessThan8_givesFalse)
{
    bool result = UserUtility::validPassword("563gd");
    ASSERT_EQ(result, false);
}
TEST(validPassword, checkingforPasswordWhichMeetsAllCondition_givesTrue)
{
    bool result = UserUtility::validPassword("sfhI8734");
    ASSERT_EQ(result, true);
}


TEST(EncryptionofPassword, checkingPasswordEncryption)
{
    std::string Encryptresult = UserUtility::encryptPassword("qwert1234");
    ASSERT_STREQ(Encryptresult.c_str(),"v|jwy6789");
}
TEST(DecryptionofPassword, checkingPasswordDecryption)
{
    std::string Decryptresult = UserUtility::getDecryptedPassword("v|jwy6789");
    ASSERT_STREQ("qwert1234", Decryptresult.c_str());
}


TEST(validUser, providingwrongUsernamePassword)
{
    bool result = UserUtility::isValidUser("karan37","jshdgwy7");
    ASSERT_EQ(result, false);
}
TEST(validUser, providingwrongPassword)
{
    bool result = UserUtility::isValidUser("aman21","uywghe73");
    ASSERT_EQ(result, false);
}
TEST(validUser, providingcorrectUsernamePassword)
{
    bool result = UserUtility::isValidUser("aman21","qwert1234");
    ASSERT_EQ(result, true);
}



int main(int argc, char **argv)
{

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}