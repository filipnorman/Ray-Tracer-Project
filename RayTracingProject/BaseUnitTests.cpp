#include "FTuple.h"
#include "gtest/gtest.h"
#include "mathFunctions/FloatOp.h"

//====================Base Tuples Testing==================//
TEST(BaseTuples, PointCheck) {
	FTuple a = FTuple(4.3f, -4.2f, 3.1f, 1.0f);
	ASSERT_EQ(4.3f, a.x);
	ASSERT_EQ(-4.2f, a.y);
	ASSERT_EQ(3.1f, a.z);
	ASSERT_EQ(1.0f, a.w);
}

TEST(BaseTuples, VectorCheck) {
	FTuple a = FTuple(4.3f, -4.2f, 3.1f, 0.0f);
	ASSERT_EQ(4.3f, a.x);
	ASSERT_EQ(-4.2f, a.y);
	ASSERT_EQ(3.1f, a.z);
	ASSERT_EQ(0.0f, a.w);
}

TEST(BaseTuples, PointFactoryCheck) {
	FTuple a = point(2.f, 2.f, 2.f);
	ASSERT_EQ(2.f, a.x);
	ASSERT_EQ(2.f, a.y);
	ASSERT_EQ(2.f, a.z);
	ASSERT_EQ(1.0f, a.w);
}

TEST(BaseTuples, VectorFactoryCheck) {
	FTuple a = vector(2.f, 2.f, 2.f);
	ASSERT_EQ(2.f, a.x);
	ASSERT_EQ(2.f, a.y);
	ASSERT_EQ(2.f, a.z);
	ASSERT_EQ(0.0f, a.w);
}

//==================Operations===========================//
TEST(TuplesOperation, EqualityCheck) {
	FTuple a = FTuple(4.3f, -4.2f, 3.1f, 0.0f);
	FTuple b = FTuple(4.3f, -4.2f, 3.1f, 0.0f);
	ASSERT_EQ(true, a == b);

	a = vector(4.3f, -4.2f, 3.1f);
	b = vector(4.3f, -4.2f, 3.1f);
	ASSERT_EQ(true, a == b);

	a = point(4.3f, -4.2f, 3.1f);
	b = point(4.3f, -4.2f, 3.1f);
	ASSERT_EQ(true, a == b);
}

TEST(TuplesOperation, AdditionCheck) {
	//Vector and Vector
	FTuple a = FTuple(1.f, -1.f, 1.0f, 0.0f);
	FTuple b = FTuple(1.3f, -1.0f, 0.5f, 0.0f);
    ASSERT_TRUE( (FTuple(2.3f, -2.f, 1.5f, 0.f) == a + b));


	a = FTuple(1.f, -1.f, 1.0f, 1.0f);
	b = FTuple(1.3f, -1.0f, 0.5f, 0.0f);
	ASSERT_TRUE((FTuple(2.3f, -2.f, 1.5f, 1.f) == a + b));

	a = FTuple(1.f, -1.f, 1.0f, 0.0f);
	b = FTuple(1.3f, -1.0f, 0.5f, 1.0f);
	ASSERT_TRUE((FTuple(2.3f, -2.f, 1.5f, 1.f) == a + b));

	//Two Points should not be added w = 2 
}

TEST(TuplesOperation, SubtractionCheck) {
	//Vector and Vector
	FTuple a = FTuple(1.f, -1.f, 1.0f, 0.0f);
	FTuple b = FTuple(1.3f, -1.0f, 0.5f, 0.0f);
	ASSERT_TRUE((FTuple(-0.3f, 0.f, 0.5f, 0.f) == a - b));


	a = FTuple(1.f, -1.f, 1.0f, 1.0f);
	b = FTuple(1.3f, -1.0f, 0.5f, 0.0f);
	ASSERT_TRUE((FTuple(-0.3f, 0.f, 0.5f, 1.f) == a - b));


	a = FTuple(1.f, -1.f, 1.0f, 0.0f);
	b = FTuple(1.3f, -1.0f, 0.5f, 1.0f);
	ASSERT_TRUE((FTuple(-0.3f, 0.f, 0.5f, -1.f) == a - b));

	a = FTuple(1.f, -1.f, 1.0f, 1.0f);
	b = FTuple(1.3f, -1.0f, 0.5f, 1.0f);
	ASSERT_TRUE((FTuple(-0.3f, 0.f, 0.5f, 0.f) == a - b));
}

TEST(TuplesOperation, NegationCheck) {
	FTuple a = FTuple(1.f, -1.f, 0.5f, 0.0f);
	ASSERT_TRUE((FTuple(-1.f, 1.f, -0.5f, 0.f) == -a));

	a = FTuple(1.f, -1.f, 0.5f, 1.0f);
	ASSERT_TRUE((FTuple(-1.f, 1.f, -0.5f, -1.f) == -a));
}

TEST(TuplesOperation, ScalarMultiplicationCheck) {
	FTuple a = FTuple(1.f, -2.f, 3.f, -4.f);
	ASSERT_TRUE((FTuple(3.5f, -7.f, 10.5f, -14.f) == a * 3.5f));
	ASSERT_TRUE((FTuple(0.5f, -1.f, 1.5f, -2.f) == a * 0.5f));
}

TEST(TuplesOperation, ScalarDivisionCheck) {
	FTuple a = FTuple(1.f, -2.f, 3.f, -4.f);
	ASSERT_TRUE((FTuple(0.5f, -1.f, 1.5f, -2.f) == a / 2.f));
	ASSERT_TRUE((FTuple(2.f, -4.f, 6.f, -8.f) == a / 0.5f));
}

TEST(TuplesOperation, MagnitudeCheck) {
	ASSERT_TRUE(equal(1.f, vector(1.f, 0.f, 0.f).magnitude()));
	ASSERT_TRUE(equal(1.f, vector(0.f, 1.f, 0.f).magnitude()));
	ASSERT_TRUE(equal(1.f, vector(0.f, 0.f, 1.f).magnitude()));
	ASSERT_TRUE(equal(sqrtf(14.f),vector(1.f, 2.f, 3.f).magnitude()));
	ASSERT_TRUE(equal(sqrtf(14.f),vector(-1.f, -2.f, -3.f).magnitude()));
}

TEST(TuplesOperation, NormalisationCheck) {
	FTuple v = vector(4.f, 0.f, 0.f);
	ASSERT_TRUE(v.normalise() == vector(1.f, 0.f, 0.f));

	v = vector(1.f, 2.f, 3.f);
	ASSERT_TRUE(v.normalise() == vector(0.26726f, 0.53452f, 0.80178f));

	ASSERT_TRUE(equal(1.f, v.normalise().magnitude()));
}

TEST(TuplesOperation, DotProductCheck) {
	FTuple a = vector(1.f, 2.f, 3.f);
	FTuple b = vector(2.f, 3.f, 4.f);
	ASSERT_TRUE(equal(dot(a, b), 20.f));
}

TEST(TuplesOperation, CrossProductCheck) {
	FTuple a = vector(1.f, 2.f, 3.f);
	FTuple b = vector(2.f, 3.f, 4.f);

	ASSERT_TRUE(cross(a, b) == vector(-1.f, 2.f, -1.f));
	ASSERT_TRUE(cross(b, a) == vector(1.f, -2.f, 1.f));
}

//=====================Colours==============================//









