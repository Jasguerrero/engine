// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <vector>

#include "impeller/geometry/path_component.h"
#include "impeller/geometry/point.h"

namespace impeller {
namespace testing {

// A heart shape with cubics.
// M140 20 C73 20 20 74 20 140 C20 275 156 310 248 443C336 311 477 270 477
// 140C477 74 423 20 357 20C309 20 267 48 248 89C229 48 188 20 140 20Z

std::vector<CubicPathComponent> golden_heart_cubics = {
    {Point(140, 20), Point(73, 20), Point(20, 74), Point(20, 140)},
    {Point(20, 140), Point(20, 275), Point(156, 310), Point(248, 443)},
    {Point(248, 443), Point(336, 311), Point(477, 270), Point(477, 140)},
    {Point(477, 140), Point(477, 74), Point(423, 20), Point(357, 20)},
    {Point(357, 20), Point(309, 20), Point(267, 48), Point(248, 89)},
    {Point(248, 89), Point(229, 48), Point(188, 20), Point(140, 20)}};

// A heart shape with quads, created from the cubics here:
// M140 20C73 20 20 74 20 140C20 275 156 310 248 443C336 311 477 270 477
// 140C477 74 423 20 357 20C309 20 267 48 248 89C229 48 188 20 140 20Z
// The values here are slightly less precise than what the polyline code
// actually generates for easier storage and reading, but still precise enough
// to work visually.
std::vector<QuadraticPathComponent> golden_heart_quads = {
    {{140, 20}, {114.723, 20.1641}, {92.9844, 29.4688}},
    {{92.9844, 29.4688}, {71.2461, 38.7734}, {54.875, 55.25}},
    {{54.875, 55.25}, {38.5039, 71.7266}, {29.3281, 93.4062}},
    {{29.3281, 93.4062}, {20.1523, 115.086}, {20, 140}},
    {{20, 140}, {20.2083, 173.521}, {30.5, 200.083}},
    {{30.5, 200.083}, {40.7917, 226.646}, {58.6667, 249}},
    {{58.6667, 249}, {76.5417, 271.354}, {99.5, 292.25}},
    {{99.5, 292.25}, {122.458, 313.146}, {148, 335.333}},
    {{148, 335.333}, {173.542, 357.521}, {199.167, 383.75}},
    {{199.167, 383.75}, {224.792, 409.979}, {248, 443}},
    {{248, 443}, {270.225, 410.208}, {295.519, 383.75}},
    {{295.519, 383.75}, {320.812, 357.292}, {346.481, 334.667}},
    {{346.481, 334.667}, {372.15, 312.042}, {395.5, 290.75}},
    {{395.5, 290.75}, {418.85, 269.458}, {437.185, 247}},
    {{437.185, 247}, {455.521, 224.542}, {466.148, 198.417}},
    {{466.148, 198.417}, {476.775, 172.292}, {477, 140}},
    {{477, 140}, {476.836, 115.086}, {467.531, 93.4062}},
    {{467.531, 93.4062}, {458.227, 71.7266}, {441.75, 55.25}},
    {{441.75, 55.25}, {425.273, 38.7734}, {403.594, 29.4688}},
    {{403.594, 29.4688}, {381.914, 20.1641}, {357, 20}},
    {{357, 20}, {332.843, 20.1389}, {311.63, 28.7778}},
    {{311.63, 28.7778}, {290.417, 37.4167}, {274.037, 52.8889}},
    {{274.037, 52.8889}, {257.657, 68.3611}, {248, 89}},
    {{248, 89}, {238.361, 68.3611}, {222.222, 52.8889}},
    {{222.222, 52.8889}, {206.083, 37.4167}, {185.111, 28.7778}},
    {{185.111, 28.7778}, {164.139, 20.1389}, {140, 20}}};

// In local testing, CPU and GPU versions of the polyline algorithm
// disagree on number of points, but both produce visually acceptable
// results.
//
// These points can be verified in an SVG like the following:
//
// <svg viewBox="0 0 500 500" xmlns="http://www.w3.org/2000/svg">
//   <polygon points="..." fill="none" stroke="red" />
// </svg>
//
// Where points looks like 140, 20 130.231, 20.415 etc. The values here are
// slightly less precise than what the polyline code actually generates for
// easier storage and reading, but still precise enough to work visually.
std::vector<Point> golden_heart_points = {
    {140, 20},          {131.765, 20.3023}, {123.672, 21.1078},
    {115.734, 22.4238}, {107.965, 24.2553}, {100.378, 26.604},
    {92.9844, 29.4688}, {85.9188, 32.7537}, {79.1253, 36.4472},
    {72.615, 40.5481},  {66.3979, 45.0528}, {60.4823, 49.956},
    {54.875, 55.25},    {49.6196, 60.8847}, {44.7551, 66.8194},
    {40.2891, 73.0478}, {36.2272, 79.5616}, {32.5731, 86.3513},
    {29.3281, 93.4062}, {26.5067, 100.762}, {24.1924, 108.297},
    {22.387, 116.001},  {21.0895, 123.861}, {20.296, 131.865},
    {20, 140},          {20.2534, 149.197}, {20.906, 158.214},
    {21.9689, 167.034}, {23.4519, 175.646}, {25.3637, 184.033},
    {27.7113, 192.184}, {30.5, 200.083},    {34.1384, 208.814},
    {38.2033, 217.323}, {42.6928, 225.603}, {47.6032, 233.646},
    {52.9299, 241.447}, {58.6667, 249},     {66.101, 257.978},
    {73.9105, 266.793}, {82.0864, 275.443}, {90.6194, 283.929},
    {99.5, 292.25},     {115.262, 306.476}, {131.433, 320.838},
    {148, 335.333},     {160.921, 346.811}, {173.756, 358.715},
    {186.505, 371.032}, {199.167, 383.75},  {207.755, 392.805},
    {216.162, 402.199}, {224.39, 411.923},  {232.439, 421.971},
    {240.308, 432.333}, {248, 443},         {255.407, 432.367},
    {263.018, 422.027}, {270.834, 411.988}, {278.856, 402.258},
    {287.084, 392.843}, {295.519, 383.75},  {308.072, 370.878},
    {320.751, 358.4},   {333.554, 346.326}, {346.481, 334.667},
    {363.181, 319.87},  {379.524, 305.229}, {395.5, 290.75},
    {404.531, 282.291}, {413.224, 273.686}, {421.57, 264.936},
    {429.56, 256.04},   {437.185, 247},     {443.055, 239.45},
    {448.516, 231.674}, {453.562, 223.678}, {458.186, 215.466},
    {462.382, 207.043}, {466.148, 198.417}, {469.016, 190.697},
    {471.437, 182.748}, {473.413, 174.582}, {474.949, 166.211},
    {476.054, 157.649}, {476.734, 148.908}, {477, 140},
    {476.697, 131.863}, {475.889, 123.858}, {474.571, 115.997},
    {472.739, 108.293}, {470.392, 100.759}, {467.531, 93.4062},
    {464.244, 86.3502}, {460.548, 79.56},   {456.446, 73.0462},
    {451.942, 66.8182}, {447.041, 60.884},  {441.75, 55.25},
    {436.116, 49.9595}, {430.182, 45.0581}, {423.954, 40.5537},
    {417.44, 36.4519},  {410.65, 32.7564},  {403.594, 29.4688},
    {396.241, 26.6083}, {388.707, 24.2609}, {381.004, 22.4285},
    {373.143, 21.1106}, {365.137, 20.3032}, {357, 20},
    {349.102, 20.2777}, {341.323, 21.0241}, {333.676, 22.2452},
    {326.17, 23.9443},  {318.818, 26.1223}, {311.63, 28.7778},
    {304.721, 31.8336}, {298.058, 35.2778}, {291.65, 39.1093},
    {285.505, 43.3251}, {279.632, 47.9205}, {274.037, 52.8889},
    {268.767, 58.1866}, {263.861, 63.7819}, {259.326, 69.6689},
    {255.169, 75.8403}, {251.393, 82.2873}, {248, 89},
    {244.622, 82.2933}, {240.874, 75.8498}, {236.755, 69.6796},
    {232.27, 63.7913},  {227.424, 58.1923}, {222.222, 52.8889},
    {216.709, 47.922},  {210.918, 43.3271}, {204.854, 39.1112},
    {198.525, 35.2792}, {191.941, 31.8344}, {185.111, 28.7778},
    {177.988, 26.1195}, {170.693, 23.9406}, {163.234, 22.242},
    {155.625, 21.0222}, {147.876, 20.277},  {140, 20}};

std::vector<Point> golden_heart_vertices = {
    {139.982, 19.5003}, {140.018, 20.4997}, {131.747, 19.8026},
    {131.783, 20.802},  {131.715, 19.8048}, {131.815, 20.7998},
    {123.622, 20.6102}, {123.721, 21.6053}, {123.59, 20.6145},
    {123.753, 21.601},  {115.652, 21.9306}, {115.816, 22.9171},
    {115.619, 21.9372}, {115.848, 22.9105}, {107.85, 23.7687},
    {108.08, 24.742},   {107.817, 23.7777}, {108.113, 24.733},
    {100.23, 26.1264},  {100.526, 27.0817}, {100.197, 26.1378},
    {100.558, 27.0703}, {92.8037, 29.0025}, {93.165, 29.935},
    {92.7736, 29.0154}, {93.1952, 29.9221}, {85.708, 32.3003},
    {86.1296, 33.2071}, {85.68, 32.3144},   {86.1576, 33.193},
    {78.8865, 36.008},  {79.3641, 36.8865}, {78.8588, 36.0242},
    {79.3918, 36.8703}, {72.3485, 40.125},  {72.8815, 40.9711},
    {72.3216, 40.1432}, {72.9084, 40.9529}, {66.1045, 44.6479},
    {66.6913, 45.4577}, {66.0788, 44.6679}, {66.717, 45.4378},
    {60.1632, 49.5711}, {60.8014, 50.341},  {60.139, 49.5924},
    {60.8255, 50.3196}, {54.5317, 54.8864}, {55.2183, 55.6136},
    {54.5094, 54.909},  {55.2406, 55.591},  {49.254, 60.5436},
    {49.9853, 61.2257}, {49.2329, 60.5677}, {50.0063, 61.2016},
    {44.3684, 66.5025}, {45.1418, 67.1364}, {44.3488, 66.5281},
    {45.1614, 67.1108}, {39.8827, 72.7564}, {40.6954, 73.3391},
    {39.8648, 72.7832}, {40.7133, 73.3123}, {35.8029, 79.297},
    {36.6515, 79.8261}, {35.7869, 79.3246}, {36.6675, 79.7985},
    {32.1328, 86.1144}, {33.0134, 86.5883}, {32.1188, 86.1424},
    {33.0273, 86.5603}, {28.8739, 93.1973}, {29.7824, 93.6152},
    {28.8613, 93.2272}, {29.795, 93.5853},  {26.0399, 100.583},
    {26.9736, 100.941}, {26.0288, 100.615}, {26.9847, 100.908},
    {23.7144, 108.15},  {24.6704, 108.444}, {23.7056, 108.183},
    {24.6792, 108.411}, {21.9002, 115.886}, {22.8738, 116.115},
    {21.8937, 115.919}, {22.8804, 116.082}, {20.5962, 123.779},
    {21.5828, 123.942}, {20.592, 123.812},  {21.5871, 123.91},
    {19.7985, 131.816}, {20.7936, 131.914}, {19.7964, 131.847},
    {20.7957, 131.883}, {19.5003, 139.982}, {20.4997, 140.018},
    {19.5002, 140.014}, {20.4998, 139.986}, {19.7536, 149.211},
    {20.7532, 149.184}, {19.7547, 149.234}, {20.7521, 149.161},
    {20.4073, 158.25},  {21.4047, 158.178}, {20.4096, 158.273},
    {21.4024, 158.154}, {21.4725, 167.094}, {22.4653, 166.975},
    {21.4761, 167.119}, {22.4616, 166.95},  {22.9592, 175.73},
    {23.9447, 175.561}, {22.9644, 175.757}, {23.9394, 175.535},
    {24.8762, 184.144}, {25.8512, 183.922}, {24.8833, 184.172},
    {25.8442, 183.895}, {27.2309, 192.322}, {28.1918, 192.045},
    {27.2398, 192.35},  {28.1828, 192.017}, {30.0285, 200.25},
    {30.9715, 199.917}, {30.0385, 200.276}, {30.9615, 199.891},
    {33.6769, 209.007}, {34.5999, 208.622}, {33.6872, 209.03},
    {34.5896, 208.599}, {37.7522, 217.539}, {38.6545, 217.108},
    {37.7638, 217.562}, {38.6429, 217.085}, {42.2532, 225.841},
    {43.1323, 225.365}, {42.266, 225.863},  {43.1195, 225.342},
    {47.1765, 233.907}, {48.03, 233.386},   {47.1903, 233.928},
    {48.0162, 233.364}, {52.517, 241.729},  {53.3428, 241.165},
    {52.5317, 241.749}, {53.3281, 241.144}, {58.2685, 249.302},
    {59.0648, 248.698}, {58.2816, 249.319}, {59.0518, 248.681},
    {65.7159, 258.297}, {66.4861, 257.659}, {65.7267, 258.309},
    {66.4752, 257.646}, {73.5363, 267.124}, {74.2848, 266.461},
    {73.5471, 267.136}, {74.2739, 266.449}, {81.723, 275.787},
    {82.4498, 275.1},   {81.7338, 275.798}, {82.439, 275.089},
    {90.2668, 284.284}, {90.972, 283.575},  {90.2775, 284.294},
    {90.9613, 283.564}, {99.1581, 292.615}, {99.8419, 291.885},
    {99.165, 292.621},  {99.835, 291.879},  {114.927, 306.847},
    {115.597, 306.104}, {114.93, 306.849},  {115.594, 306.102},
    {131.101, 321.212}, {131.765, 320.464}, {131.104, 321.215},
    {131.762, 320.462}, {147.671, 335.71},  {148.329, 334.957},
    {147.668, 335.707}, {148.332, 334.96},  {160.589, 347.185},
    {161.253, 346.437}, {160.581, 347.178}, {161.261, 346.445},
    {173.416, 359.081}, {174.096, 358.348}, {173.409, 359.074},
    {174.104, 358.355}, {186.158, 371.391}, {186.853, 370.672},
    {186.151, 371.385}, {186.86, 370.679},  {198.812, 384.103},
    {199.521, 383.397}, {198.804, 384.094}, {199.529, 383.406},
    {207.392, 393.149}, {208.117, 392.461}, {207.382, 393.138},
    {208.127, 392.471}, {215.79, 402.532},  {216.535, 401.865},
    {215.781, 402.522}, {216.544, 401.876}, {224.009, 412.246},
    {224.772, 411.6},   {224, 412.236},     {224.781, 411.611},
    {232.049, 422.283}, {232.829, 421.658}, {232.041, 422.273},
    {232.837, 421.668}, {239.91, 432.635},  {240.707, 432.03},
    {239.903, 432.625}, {240.714, 432.04},  {247.594, 443.292},
    {248.406, 442.708}, {248.41, 443.286},  {247.59, 442.714},
    {255.817, 432.652}, {254.996, 432.081}, {255.809, 432.663},
    {255.004, 432.07},  {263.421, 422.323}, {262.615, 421.73},
    {263.412, 422.334}, {262.623, 421.72},  {271.229, 412.296},
    {270.44, 411.681},  {271.22, 412.306},  {270.448, 411.67},
    {279.242, 402.576}, {278.471, 401.94},  {279.233, 402.587},
    {278.48, 401.929},  {287.461, 393.172}, {286.708, 392.514},
    {287.451, 393.183}, {286.718, 392.503}, {295.885, 384.09},
    {295.152, 383.41},  {295.876, 384.099}, {295.161, 383.401},
    {308.43, 371.227},  {307.714, 370.529}, {308.423, 371.234},
    {307.721, 370.522}, {321.101, 358.756}, {320.4, 358.043},
    {321.094, 358.764}, {320.408, 358.036}, {333.897, 346.69},
    {333.211, 345.962}, {333.889, 346.697}, {333.219, 345.955},
    {346.816, 335.038}, {346.147, 334.295}, {346.813, 335.041},
    {346.15, 334.292},  {363.513, 320.244}, {362.85, 319.495},
    {363.515, 320.242}, {362.848, 319.497}, {379.858, 305.602},
    {379.191, 304.857}, {379.86, 305.6},    {379.189, 304.859},
    {395.836, 291.12},  {395.164, 290.38},  {395.842, 291.115},
    {395.158, 290.385}, {404.872, 282.656}, {404.189, 281.926},
    {404.882, 282.647}, {404.179, 281.936}, {413.576, 274.042},
    {412.872, 273.331}, {413.586, 274.032}, {412.862, 273.341},
    {421.932, 265.281}, {421.208, 264.591}, {421.942, 265.27},
    {421.198, 264.602}, {429.932, 256.374}, {429.188, 255.706},
    {429.943, 256.362}, {429.178, 255.718}, {437.567, 247.322},
    {436.803, 246.678}, {437.58, 247.307},  {436.79, 246.693},
    {443.45, 239.757},  {442.66, 239.143},  {443.464, 239.737},
    {442.646, 239.163}, {448.926, 231.962}, {448.107, 231.387},
    {448.939, 231.941}, {448.094, 231.408}, {453.985, 223.945},
    {453.139, 223.411}, {453.998, 223.923}, {453.126, 223.433},
    {458.621, 215.711}, {457.75, 215.22},   {458.633, 215.689},
    {457.738, 215.243}, {462.83, 207.266},  {461.935, 206.82},
    {462.841, 207.243}, {461.924, 206.843}, {466.606, 198.617},
    {465.69, 198.217},  {466.617, 198.591}, {465.679, 198.243},
    {469.485, 190.871}, {468.547, 190.522}, {469.494, 190.842},
    {468.538, 190.551}, {471.915, 182.893}, {470.958, 182.602},
    {471.922, 182.865}, {470.951, 182.63},  {473.898, 174.7},
    {472.927, 174.464}, {473.904, 174.672}, {472.921, 174.492},
    {475.441, 166.302}, {474.457, 166.121}, {475.445, 166.275},
    {474.453, 166.147}, {476.55, 157.713},  {475.558, 157.585},
    {476.552, 157.688}, {475.555, 157.61},  {477.232, 148.946},
    {476.235, 148.869}, {477.234, 148.922}, {476.234, 148.893},
    {477.5, 140.015},   {476.5, 139.985},   {477.5, 139.981},
    {476.5, 140.019},   {477.196, 131.844}, {476.197, 131.882},
    {477.194, 131.813}, {476.199, 131.913}, {476.387, 123.807},
    {475.392, 123.908}, {476.383, 123.775}, {475.396, 123.94},
    {475.065, 115.914}, {474.078, 116.079}, {475.058, 115.881},
    {474.085, 116.112}, {473.226, 108.177}, {472.253, 108.409},
    {473.216, 108.144}, {472.262, 108.442}, {470.869, 100.61},
    {469.914, 100.908}, {470.858, 100.578}, {469.926, 100.94},
    {467.997, 93.225},  {467.065, 93.5875}, {467.984, 93.1951},
    {467.078, 93.6174}, {464.697, 86.1391}, {463.79, 86.5614},
    {464.683, 86.1112}, {463.804, 86.5892}, {460.987, 79.321},
    {460.109, 79.799},  {460.971, 79.2935}, {460.125, 79.8264},
    {456.869, 72.7797}, {456.023, 73.3126}, {456.851, 72.7531},
    {456.041, 73.3392}, {452.347, 66.5252}, {451.537, 67.1112},
    {452.327, 66.4998}, {451.556, 67.1366}, {447.426, 60.5656},
    {446.655, 61.2024}, {447.405, 60.5417}, {446.676, 61.2262},
    {442.115, 54.9077}, {441.385, 55.5923}, {442.092, 54.8855},
    {441.408, 55.6145}, {436.458, 49.595},  {435.774, 50.3239},
    {436.434, 49.5739}, {435.798, 50.345},  {430.5, 44.6726},
    {429.863, 45.4436}, {430.475, 44.653},  {429.889, 45.4633},
    {424.247, 40.1486}, {423.661, 40.9588}, {424.22, 40.1306},
    {423.687, 40.9768}, {417.706, 36.0288}, {417.174, 36.875},
    {417.679, 36.0127}, {417.201, 36.8911}, {410.889, 32.3172},
    {410.411, 33.1956}, {410.861, 32.3032}, {410.439, 33.2096},
    {403.805, 29.0155}, {403.383, 29.922},  {403.775, 29.0028},
    {403.412, 29.9347}, {396.422, 26.1423}, {396.06, 27.0743},
    {396.39, 26.131},   {396.092, 27.0857}, {388.856, 23.7835},
    {388.558, 24.7382}, {388.823, 23.7744}, {388.591, 24.7473},
    {381.119, 21.9421}, {380.888, 22.915},  {381.086, 21.9354},
    {380.921, 22.9217}, {373.225, 20.6175}, {373.06, 21.6037},
    {373.193, 20.6131}, {373.092, 21.608},  {365.187, 19.8057},
    {365.087, 20.8007}, {365.156, 19.8036}, {365.118, 20.8029},
    {357.019, 19.5003}, {356.981, 20.4997}, {356.982, 19.5003},
    {357.018, 20.4997}, {349.084, 19.778},  {349.12, 20.7773},
    {349.054, 19.7799}, {349.15, 20.7754},  {341.275, 20.5264},
    {341.371, 21.5218}, {341.244, 20.5304}, {341.402, 21.5179},
    {333.597, 21.7514}, {333.754, 22.7389}, {333.565, 21.7575},
    {333.786, 22.7329}, {326.06, 23.4566},  {326.281, 24.4319},
    {326.028, 23.4649}, {326.312, 24.4237}, {318.676, 25.6429},
    {318.96, 26.6017},  {318.645, 25.6533}, {318.991, 26.5914},
    {311.456, 28.3088}, {311.803, 29.2468}, {311.427, 28.3205},
    {311.832, 29.235},  {304.519, 31.3764}, {304.923, 32.2909},
    {304.492, 31.3895}, {304.951, 32.2778}, {297.828, 34.8336},
    {298.287, 35.722},  {297.801, 34.8487}, {298.314, 35.707},
    {291.393, 38.6801}, {291.906, 39.5384}, {291.367, 38.697},
    {291.932, 39.5216}, {285.222, 42.9128}, {285.788, 43.7374},
    {285.197, 42.9313}, {285.813, 43.7189}, {279.324, 47.5267},
    {279.94, 48.3143},  {279.3, 47.5467},   {279.964, 48.2944},
    {273.705, 52.515},  {274.369, 53.2628}, {273.683, 52.5363},
    {274.392, 53.2415}, {268.412, 57.834},  {269.121, 58.5393},
    {268.391, 57.857},  {269.143, 58.5163}, {263.485, 63.4523},
    {264.237, 64.1116}, {263.465, 63.4768}, {264.257, 64.087},
    {258.93, 69.3638},  {259.722, 69.974},  {258.912, 69.3896},
    {259.741, 69.9483}, {254.754, 75.561},  {255.584, 76.1196},
    {254.738, 75.5876}, {255.601, 76.093},  {250.962, 82.0346},
    {251.825, 82.54},   {250.947, 82.0618}, {251.839, 82.5129},
    {247.554, 88.7744}, {248.446, 89.2256}, {248.447, 88.7751},
    {247.553, 89.2249}, {245.069, 82.0684}, {244.176, 82.5182},
    {245.055, 82.0419}, {244.19, 82.5447},  {241.306, 75.5984},
    {240.442, 76.1013}, {241.29, 75.5723},  {240.458, 76.1274},
    {237.171, 69.402},  {236.339, 69.9572}, {237.153, 69.3766},
    {236.357, 69.9825}, {232.668, 63.4883}, {231.872, 64.0942},
    {232.648, 63.464},  {231.892, 64.1185}, {227.802, 57.8651},
    {227.046, 58.5196}, {227.781, 57.8422}, {227.067, 58.5424},
    {222.579, 52.5388}, {221.865, 53.239},  {222.557, 52.5174},
    {221.888, 53.2604}, {217.044, 47.5505}, {216.374, 48.2934},
    {217.02, 47.5303},  {216.398, 48.3137}, {211.228, 42.9354},
    {210.607, 43.7188}, {211.203, 42.9166}, {210.632, 43.7376},
    {205.139, 38.7007}, {204.568, 39.5217}, {205.113, 38.6835},
    {204.595, 39.5389}, {198.784, 34.8515}, {198.266, 35.7069},
    {198.757, 34.8362}, {198.294, 35.7223}, {192.173, 31.3913},
    {191.709, 32.2774}, {192.145, 31.378},  {191.737, 32.2908},
    {185.315, 28.3214}, {184.907, 29.2342}, {185.286, 28.3093},
    {184.936, 29.2462}, {178.163, 25.6511}, {177.814, 26.588},
    {178.132, 25.6404}, {177.845, 26.5986}, {170.836, 23.4615},
    {170.55, 24.4197},  {170.804, 23.4531}, {170.582, 24.4281},
    {163.345, 21.7545}, {163.123, 22.7295}, {163.313, 21.7483},
    {163.155, 22.7357}, {155.704, 20.5285}, {155.546, 21.5159},
    {155.673, 20.5245}, {155.577, 21.5199}, {147.924, 19.7793},
    {147.828, 20.7747}, {147.893, 19.7773}, {147.858, 20.7767},
    {140.018, 19.5003}, {139.982, 20.4997}, {140, 20},
    {140, 20}};
}  // namespace testing
}  // namespace impeller
