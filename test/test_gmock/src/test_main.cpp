/*
 Copyright (c) 2014-present PlatformIO <contact@platformio.org>

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
**/

#include <gtest/gtest.h>
#include "include/mock_turtle.h"
#include "include/painter.h"

using ::testing::AtLeast;
TEST(PainterTest, CanDrawSomething)
{
	MockTurtle turtle;
	EXPECT_CALL(turtle, PenDown())
		.Times(AtLeast(1));

	Painter painter(&turtle);

	EXPECT_TRUE(painter.DrawCircle(0, 0, 10));
}




#ifdef GD32F3x0
/* to avoid code duplication: let's use the same .c file as in the embedded folder already. */
/* a bit hacky and makes us dependent on test_embedded existing. Copy-paste code if needed. */

#include "../gd32_config.c"

int main(int argc, char **argv)
{
    gd32Start();
    ::testing::InitGoogleTest(&argc, argv);
	if (RUN_ALL_TESTS())
	;
	// Always return zero-code and allow PlatformIO to parse results
	return 0;
}


#else

int main(int argc, char **argv)
{
	::testing::InitGoogleMock(&argc, argv);
	if (RUN_ALL_TESTS())
	;
	// Always return zero-code and allow PlatformIO to parse results
	return 0;
}

#endif