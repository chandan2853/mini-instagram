#include "../src/instagram.cpp"
#include "./gtest/gtest.h"

TEST(TimelineFile, checkThatTimelineFileAvailableTrue)
{
    bool result = Instagram::validateFileLocation("."+timelinePath);
    ASSERT_EQ(result, true);
}
TEST(UserInfoFile, checkThatUserInfoAvailableTrue)
{
    bool result = Instagram::validateFileLocation("."+UserInfoFilePath);
    ASSERT_EQ(result, true);
}


TEST(LikePost, LikePostSuccessfully)
{
    bool result = Timeline::likePost(2,3,"chandan23");
    ASSERT_EQ(result, true);
}
TEST(LikePost, UnlikePostWhichisAlreadyLiked)
{
    bool result = Timeline::likePost(2,3,"chandan23");
    ASSERT_EQ(result, true);
}
TEST(LikePost, InvalidPosttoLike)
{
    bool result = Timeline::likePost(2,1,"chandan23");
    ASSERT_EQ(result, false);
}



int main(int argc, char **argv)
{

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}