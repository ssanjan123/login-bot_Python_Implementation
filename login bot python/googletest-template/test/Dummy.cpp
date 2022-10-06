#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Parallelogram.h"
#include "Matthews.h"
#include "Awards.h"
#include<iostream>
using namespace std;
using namespace testing;
using shapes::Parallelogram;
using sequence::MatthewsOutcome;
using awards::AwardCeremonyActions;
using awards::RankList;
using ::testing::Return;
//Tests that fail for incorrect codes

class MockAwardCeremonyActions : public AwardCeremonyActions {
public:
  MOCK_METHOD(void, playAnthem, (), (override));
  MOCK_METHOD(void, turnOffTheLightsAndGoHome,(),(override));
  MOCK_METHOD(void, awardBronze, (std::string recipient), (override));
  MOCK_METHOD(void, awardSilver, (std::string recipient), (override));
  MOCK_METHOD(void, awardGold, (std::string recipient), (override));
};

class MockRankList : public RankList {
public:
  MOCK_METHOD(std::string, getNext, (), (override));
};


TEST(ParallelogramTests, PerimeterTestFail){

    Parallelogram par(shapes::Side(1),shapes::Side(2),shapes::Angle(45));
    EXPECT_EQ(6,par.getPerimeter());
}

TEST(ParallelogramTests, AreaTestFail){

    Parallelogram par(shapes::Side(3),shapes::Side(2),shapes::Angle(90));
    EXPECT_EQ(6,par.getArea());
}

TEST(ParallelogramTests, KindTestFail){

    Parallelogram par(shapes::Side(2),shapes::Side(2),shapes::Angle(90));
    auto k = par.getKind();
    EXPECT_EQ(shapes::Parallelogram::Kind::SQUARE,k);
}

//Tests that pass
TEST(ParallelogramTests, PerimeterTestPass){

    Parallelogram par(shapes::Side(2),shapes::Side(2),shapes::Angle(45));
    EXPECT_EQ(8,par.getPerimeter());
}

TEST(ParallelogramTests, AreaTestPass){

    Parallelogram par(shapes::Side(3),shapes::Side(3),shapes::Angle(90));
    EXPECT_EQ(9,par.getArea());
}

TEST(ParallelogramTests, KindTestPass){

    Parallelogram par(shapes::Side(2),shapes::Side(1),shapes::Angle(90));
    auto k = par.getKind();
    EXPECT_EQ(shapes::Parallelogram::Kind::RECTANGLE,k);
}



//This test is a check for MINUS_TWO_CYCLE without the value initially being -2
TEST(MatthewsTests, MinusTwoPassTest){
    auto m = sequence::checkMatthewsOutcome(-10);
    ASSERT_EQ(MatthewsOutcome::MINUS_TWO_CYCLE,m);
}

//This test goes from 1 to 100 showing that every end remainder comes to 0 for positive values
TEST(MatthewsTests, ZeroTEst){
    for(int i=0;i<=100;i++){
    auto m = sequence::checkMatthewsOutcome(i);
    ASSERT_EQ(MatthewsOutcome::ZERO,m);
    }
}


//Passes only when value is -1
TEST(MatthewsTests, MinusOnePassTest){
    auto m = sequence::checkMatthewsOutcome(-1);
    ASSERT_EQ(MatthewsOutcome::MINUS_ONE_CYCLE,m);

} 
//All fails for Minus Cycle except for the value being -1
TEST(MatthewsTests, MinusOneFailTest){
     int i=-2;
    for(i;i>=-1000000;i--){
    auto m = sequence::checkMatthewsOutcome(i);
    if(m == MatthewsOutcome::MINUS_ONE_CYCLE)
        break;
    }
    auto m = sequence::checkMatthewsOutcome(i);
    ASSERT_EQ(MatthewsOutcome::MINUS_ONE_CYCLE,m);
}


TEST(AwardsTests, TestAwardActions) {
  MockAwardCeremonyActions action;  
  {
    InSequence seq;//Sequence of actions
    EXPECT_CALL(action, playAnthem()).Times(1);
    EXPECT_CALL(action, awardBronze).Times(1);
    EXPECT_CALL(action, awardSilver).Times(1);
    EXPECT_CALL(action, awardGold).Times(1); 
    EXPECT_CALL(action, turnOffTheLightsAndGoHome()).Times(1); 
  }
  action.playAnthem();
  action.awardBronze("Jack");
  action.awardSilver("Jill");
  action.awardGold("Sarah");
  action.turnOffTheLightsAndGoHome();
}


TEST(AwardsTests, TestRankList) {
    MockRankList ranks;
    MockAwardCeremonyActions actions;
    std::string name1("Jack");
    std::string name2("Jill");
    std::string name3("John");
    //Return once 3 times so the function must be called thrice
    EXPECT_CALL(ranks, getNext()).WillOnce(Return(name1))
    .WillOnce(Return(name2))
    .WillOnce(Return(name3));
    EXPECT_CALL(actions, awardBronze(name1)).Times(1);
    EXPECT_CALL(actions, awardSilver(name2)).Times(1);
    EXPECT_CALL(actions, awardGold(name3)).Times(1);

    //Testing getnext() being sent to awardBronze,silver,gold
    actions.awardBronze(ranks.getNext()=name1);
    actions.awardSilver(ranks.getNext()=name2);
    actions.awardGold(ranks.getNext()=name3);
}
