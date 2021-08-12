#include "FTuple.h"
#include "Colour.h"
#include "Canvas.h"
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

TEST(ColourObject, ColourCheck) {
	Colour c = Colour(-0.5f, 0.4f, 1.7f);
	
	ASSERT_TRUE(equal(c.red(), -0.5f));
	ASSERT_TRUE(equal(c.green(), 0.4f));
	ASSERT_TRUE(equal(c.blue(), 1.7f));
}

TEST(ColourObject, AdditionCheck) {
	Colour c1 = Colour(0.9f, 0.6f, 0.75f);
	Colour c2 = Colour(0.7f, 0.1f, 0.25f);

	//Limiting the colour prematurely will cause unwanted colours. Only simplify to 0 and 1 as the final calculation.
	ASSERT_TRUE(c1 + c2 == Colour(1.6f, 0.7f, 1.f));
}

TEST(ColourObject, SubtractionCheck) {
	Colour c1 = Colour(0.9f, 0.6f, 0.75f);
	Colour c2 = Colour(0.7f, 0.1f, 0.25f);

	ASSERT_TRUE(c1 - c2 == Colour(0.2f, 0.5f, 0.5f));
}

TEST(ColourObject, ScalarMultiplicationCheck) {
	Colour c = Colour(0.2f, 0.3f, 0.4f);

	ASSERT_TRUE((c * 2.f) == Colour(0.4f, 0.6f, 0.8f));
}

TEST(ColourObject, MultiplicationCheck) {
	Colour c1 = Colour(1.f, 0.2f, 0.4f);
	Colour c2 = Colour(0.9f, 1.f, 0.1f);

	ASSERT_TRUE(c1 * c2 == Colour(0.9f, 0.2f, 0.04f));
}

//=============================Canvas Testing==========================================//

TEST(CanvasObject, CanvasInitialisationCheck) {
	Canvas canvas = Canvas(10, 20);
	ASSERT_EQ(10, canvas.m_width);
	ASSERT_EQ(20, canvas.m_height);
	ASSERT_TRUE( Colour(0.f,0.f,0.f) == canvas.getPixelColour(4, 5));
	canvas.write_pixel(4, 5, Colour(1.f, 0.f, 0.f));
	ASSERT_TRUE(Colour(1.f, 0.f, 0.f) == canvas.getPixelColour(4, 5));
}

TEST(CanvasObject, CanvasReadWriteCheck) {
	Canvas canvas = Canvas(10, 20);
	ASSERT_TRUE(Colour(0.f, 0.f, 0.f) == canvas.getPixelColour(2, 3));
	canvas.write_pixel(2, 3, Colour(1.f, 0.f, 0.f));
	ASSERT_TRUE(Colour(1.f, 0.f, 0.f) == canvas.getPixelColour(2, 3));
}

TEST(CanvasObject, ConstructionOfPPMContainerCheck) {
	Canvas canvas = Canvas(5, 3);

	PPMContainer container = canvas.canvasToPPM();

	ASSERT_TRUE(container.magicNumber == std::string("P3\n5 3\n255\n"));

}











