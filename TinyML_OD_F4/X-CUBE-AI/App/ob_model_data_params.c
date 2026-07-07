/**
  ******************************************************************************
  * @file    ob_model_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    2026-07-05T12:54:17+0330
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#include "ob_model_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_ob_model_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_ob_model_weights_array_u64[377] = {
  0x3e469c68bfab68bcU, 0x4029cb61bfc9d947U, 0xbfaf1131c06787c4U, 0xc043ef4ec08709e8U,
  0xbfdb442a403c9e85U, 0xbfc23355bfcd1ef3U, 0x4123c605be915a20U, 0x3e9910fec08f7520U,
  0xbe1678fb408d59a5U, 0xbee501a9c01b3ce1U, 0xc05bd93440187ae4U, 0x3fd327b0c029ff3dU,
  0x3e1c66b1c0563686U, 0xbfe6ff3d3fbe5f50U, 0xc00cf512c036da04U, 0x40a42081bfcbd411U,
  0xc034cecd401cd0ccU, 0xc0302431bf23ea98U, 0xbf9d686e3f89cd3eU, 0xbf2d5870c01b6a4bU,
  0xbfadf3ebbffd828dU, 0xc00fa7413f6427c6U, 0x3e8a75c3c007282cU, 0xc08f09243f239eb4U,
  0xc038e7c7c06b7592U, 0x3f25e0b3bfff477aU, 0x3fbc8acf3eb9b07eU, 0x3e291910bfa96531U,
  0xc01a15d04041873eU, 0xc0145f6ec07bfc18U, 0xbcd8df583fa684c6U, 0x3fc4be89c052dbafU,
  0x3f41359e3edcb53bU, 0x4059578740627f9fU, 0xc060af96405735d1U, 0x3fa768d0bfe99502U,
  0xc0284fbf408610e5U, 0x4045d902403d9a28U, 0x40878c05409273eeU, 0xc082ff644077a64eU,
  0x3ea115f53e16e543U, 0x3e44452bbc1272a8U, 0xbdac69e83e083008U, 0xbe8fbd91be7c0f25U,
  0xbd2ab7f4bc80fd00U, 0x3e939703be9bbbbbU, 0xbe4d175d3e15e2c5U, 0x3e49a7873e9a19d5U,
  0x3e1396533e23d3aeU, 0xbe9083843e0b7308U, 0x3e6b7b2b3d846ceaU, 0xbe7947b83e577c5eU,
  0x3e21edd5be03329aU, 0x3d742a53bde7865bU, 0x3e8a150bbd65291bU, 0xbe5e5bc73dfb63d6U,
  0xbe60b53b3e4450e0U, 0xbe57a12cbe53f602U, 0x3ea5ecc4bd9a1000U, 0x3e6bfb8c3e9b340cU,
  0x3e3d402ebe4a2e53U, 0xbe0096683cf9fabcU, 0xbebf5fc73e897e46U, 0x3ca873683d8cbba2U,
  0x3e17ac6bbe2af86bU, 0xbe4faf57be2fe7bcU, 0x3e98e8ed3d3947bdU, 0xbe42202a3d9987deU,
  0xbe85ce5bbdc120f8U, 0x3e185e2f3e8c862eU, 0xbcdd5cf2bd5ef452U, 0xbeb7b5923db86308U,
  0xbe13fe903e23ac46U, 0xbe5deec3be597399U, 0x3e1f573abd867fbbU, 0x3db138a73e387fd6U,
  0x0U, 0x0U, 0x0U, 0x0U,
  0xbfa45d3b3fdd161aU, 0xbefa45edbf88c07cU, 0x3f49e5173f371b7bU, 0xc00908443fd8cd3bU,
  0x3fcefa61bf8b14e7U, 0xbd6811123fd4b994U, 0xbf5031f4bf37ed83U, 0x3f53066ebfa02bb9U,
  0x3f50b3edbf25db0aU, 0xbf87347d3f7be238U, 0x3f63f54e3fc5c734U, 0xbf8583dcbf5f873aU,
  0xbf03b6303e86c3b0U, 0x3e814a743e68e166U, 0x3f17a0013fc4af23U, 0xbf94c089bf3549aeU,
  0xbf2c9e2abd9de83bU, 0xbf61f3a1bf9731f9U, 0xbfa6d9a5bfc3c93dU, 0xbf527c83bf90fd8bU,
  0x3fc5d6ebbf344659U, 0x3f6c91633eb85488U, 0x3e9308cd3c89cf80U, 0xbeeac3843f963bcaU,
  0xbf33732bbdb26dd7U, 0x3fafa4f4bf0b213bU, 0xbf84146a3f0d46aeU, 0x3fc20d0a3fc18f04U,
  0x3f2dfc8a3f741ed2U, 0x3f6fb1fd3ea9004eU, 0x3fb753c1bf0dbf7fU, 0x3def0cf63f4b1879U,
  0x3fd67fa4bf504598U, 0x3e278a813f86069dU, 0x3f67d9a63e9d2f39U, 0xbfdc58d1bfcfbd1bU,
  0x3f92394fbfb88a15U, 0x3fb679663fe84b5eU, 0x3c4714fe3f0ede64U, 0xbf999d5d3ea78068U,
  0x40028cd33f1d656dU, 0x3e0fc518bfa5eec0U, 0xbf390344bee1730bU, 0xbed0b1813f19bf51U,
  0x3f9538ea3f5bdf40U, 0xbf55475a3f23081cU, 0xbfcc5e603e53afceU, 0xbe055d3bbf99bb75U,
  0x3f763c22bf5b1d50U, 0xbfd787f63fb06028U, 0xbfa2c97d3e65b48aU, 0xbfa676a3bfd9a0dbU,
  0x3f1e0e0dbf5f9d35U, 0x3fa80b193f9595dbU, 0x3d61deb83fb1db63U, 0x3e00c064be2886b9U,
  0x3f3aa1e13fb6b237U, 0x3ee107513f06fcd8U, 0xbfa88c973d88ad5dU, 0xbefb6ebfbedb7acbU,
  0xbf4eb4b7bfa78260U, 0xbe06fa1b3f605331U, 0x3e2c6e5e3f9be64eU, 0xbf79f0843efd0d93U,
  0xbea43730be91a860U, 0xbf0b312bbfaa29bdU, 0xbf12666e3ed4b44cU, 0x3e42cb433f195e91U,
  0xbf318b76bf89f9afU, 0xbf985a9cbf6b561cU, 0xbf0b7d5cbfa9341bU, 0xbe946f6bbf4dc9afU,
  0x3e3a64193e640dc0U, 0x3d30f27ebd8ee6e2U, 0x3e55c3353e943c2fU, 0x3df08b4c3e89ac49U,
  0x3e0463e03e186ce1U, 0x3e2931733e08e5b8U, 0x3e7d68393e6cff4fU, 0x3ba5025fbc93b5deU,
  0x3de039eebd5ca449U, 0xbe02185cbc886db0U, 0x3b9c5ecebe1eef8fU, 0xbd609b903e2ee728U,
  0xbe75ebea3dbb480eU, 0x3e8632aebe138eacU, 0x3e59d1523d909a9aU, 0xbe72f130bb9e30cbU,
  0x3d11b5d43e3e00f9U, 0xbca7cabd3ea729e0U, 0x3d80e03bbd979cf2U, 0x3d9dc6973cc29514U,
  0x3c9a33f3be19e75cU, 0x3e1c2a42bc5ffaceU, 0x3e6b8fd73e6c9eeaU, 0x3e9c282dbe7ea910U,
  0xbe1128bc3d60a767U, 0xbdcf8fad3e490cf9U, 0xbe14dd9abe126da0U, 0xbea3861b3d26a551U,
  0x3e4f3b24bd6449aeU, 0xbdfe6b3c3cdf5a5eU, 0x3ea031b03e0641f0U, 0xbdfd1af9be5441c7U,
  0xbe1ab40e3e2a1bd0U, 0x3e64504ebe1608e4U, 0x3d3d2af5bd80822aU, 0x3ea393203e3ec066U,
  0x3e51db533e17b5f6U, 0xbe929ecabe45b1c0U, 0xbeb6babc3e199b11U, 0xbe0cc9f03e25b200U,
  0xbe5bc279be93fa66U, 0xbe63aead3d7b2a0cU, 0xbdc5a79cbc1fba3aU, 0x3ccfee36be90ec5dU,
  0x3e888f29be715e4bU, 0x3e9ab9003cd77c33U, 0x3e96146d3e1fbf1bU, 0x3cf6c1de3e2710acU,
  0x3e3789bbbeb136e0U, 0x3ea28146be84eea5U, 0xbe3492f83e6b4b69U, 0x3e77495e3e8f3756U,
  0x3e913b87bcffaf53U, 0x3eb298fd3e36645bU, 0xbc3efde2bdba1d89U, 0xbdaef89cbd8ad6acU,
  0xbe2cb5f0bd99d5b7U, 0xbe5b2127be3a29dfU, 0x3e52f2c93e74df76U, 0xbe094b983da5d17aU,
  0x3e3bdf743d0f6f9fU, 0xbddceaf3bea7b0ffU, 0xbe6b7685be8ccd5aU, 0x3e2842f83e45a7b2U,
  0x3d5613383eabddd8U, 0xbd441ffd3e0f1647U, 0xbdf111523db89df4U, 0x3d3471ecbe24adf3U,
  0x3cf6f688be075da3U, 0xbe7a0915bd32bd9bU, 0x3e85ae7b3e48600cU, 0x3c7858103dd570faU,
  0x0U, 0x0U, 0x0U, 0x0U,
  0x0U, 0x0U, 0x0U, 0x0U,
  0x3f1f8521be2dd4d6U, 0xbf306d723f45a250U, 0xbef1f4a73c602031U, 0x3f426bd6bdf5c900U,
  0xbebaa613be380846U, 0xbe42b201bf08518cU, 0x3e3a877d3ec20b02U, 0xbe61ea0b3d259874U,
  0xbf8a9fb63ec6d964U, 0xbfce7bf03eda7890U, 0x3d75bfcabf66621dU, 0xbfd156c5bfa1d8e1U,
  0x3ec6db373eeccaecU, 0x3f2a98a73d59dafdU, 0x3e7537c73fbd1e69U, 0x3f2faba4bee6ee5aU,
  0x3f52bc433ecd44adU, 0x3f72d8063f0fd1b2U, 0x3edff70a3e3d6212U, 0x3e3b0fe63cec1c0dU,
  0x3ecd6080bcf59da8U, 0x3ee6d4b63e586a73U, 0xbf43b68e3e935088U, 0xbd8879ecbe1c73f8U,
  0x3ecd9f9dbf151202U, 0xbe46742d3d8e5983U, 0x3e3307e0be59ce3aU, 0xbf0494a33f3ccbc3U,
  0x3eb94e9e3f1eb152U, 0xbf0d39fdbe98b57eU, 0x3edc018dbe09ad27U, 0xbefb84033e14ddd6U,
  0x3dcc059bbe7840cfU, 0x3ece687f3ef2cb02U, 0x3f1a1245bf3d8993U, 0xbe1e3e4cbf7a2559U,
  0x3f068549bf2c9f55U, 0xbf29dd89be0d7aabU, 0xbf0c2a14bf48e975U, 0xbf40f9e6bf1554b4U,
  0x3ea6bbedbf0591d7U, 0xbf0ad3b53da43f67U, 0xbc9ee74abea77a6cU, 0xbe88aa663ee95999U,
  0x3dcd2650be8dad9eU, 0xbdf4486a3e993395U, 0x3ec8bfaf3e3e9453U, 0xbf1ee75dbf17e63fU,
  0x3d5a11403aec78b0U, 0x3ef200cabf1613cbU, 0x3dd9e7ccbcc3055aU, 0x3e51c8233eb13251U,
  0xbd73c7423d896659U, 0x3ecb50093d79c882U, 0xbf1a8ddabed03751U, 0xbf0312573eedf4a8U,
  0xbf21d1f1be46430fU, 0x3d10b9643e5274ffU, 0x3f1a82fbbe4d644eU, 0x3f3666663f022ff7U,
  0x3f5a11903ec7cafaU, 0xbf223a6abf69ad06U, 0x3ed697b2beed2284U, 0xbe3d7513bef2f84cU,
  0xbe8fbdbc3e27e082U, 0x3f2ab67dbeab9c96U, 0x3e88a18b3e1b32d1U, 0x3ef2a9d9bec1b46bU,
  0x3e4e5acfbebb2b45U, 0x3f4445573e263258U, 0x3e4e45e03e987827U, 0x3f065040bc27600eU,
  0x3f2584b9bf27b344U, 0x3e92b0edbee72d17U, 0xbe88f4533d1a8777U, 0x3dcf0d53bdb6d58bU,
  0x3eecc65f3f67b966U, 0xbf20c3353f44ec65U, 0xbed9b9fb3e91dbd8U, 0xbf556a0cbea31560U,
  0xbf12eefdbf441833U, 0x3eebba8d3ec606d4U, 0xbf15fc903ef8d5d9U, 0xbbd335663f95fb92U,
  0xbf4932703f33cc1cU, 0xbeeac9ccbefcf827U, 0x3e4f4a8f3eab7b07U, 0xbf2940f5be764fb4U,
  0xbfad149b3d7db86dU, 0xbf83d13e3f2eb118U, 0xbf4519ec3f3929c8U, 0x3e0eff7cbf328d72U,
  0x3e407da13e5b253dU, 0x3eca8212bf178de2U, 0xbb98fa783f8dc810U, 0xbecea6dbbf27fdaeU,
  0xbee361f13e9b8b37U, 0xbef312773eb83769U, 0x3f0820623ec562a6U, 0xbe238257bea35becU,
  0xbefe05293e969860U, 0x3f7b18483e024a68U, 0xbeac34963d635283U, 0x3ef1c5563f32dd13U,
  0xbf2397303ef71cd0U, 0xbeb6ac833f61b12fU, 0xbf285664be9f7042U, 0x3f29b4263e3a818cU,
  0x3f4a87e5bee581c3U, 0xbeeb2235bec5557fU, 0x3e6961263ea1851fU, 0xbebd0209bf14ce74U,
  0xbe8bc52e3f866abdU, 0xbe46fc2fbf80d055U, 0x3ea018553e5cf750U, 0xbe4000b4be317961U,
  0x3ea1cbb1be8185c4U, 0x3f0c2031be937f64U, 0x3f240ab63ea20a31U, 0xbef458883db38d78U,
  0xbe6d3b2c3edd7c2dU, 0x3d8a8d3cbed00a98U, 0xbebc2088be7b12b1U, 0x3e9391aebe3d0021U,
  0xbe0f64dcbe9cfaf0U, 0x3f044cb7bdbf098fU, 0xbe43b532bf14c783U, 0x3f1ed5133d413b4bU,
  0x3f85968f3e97448cU, 0x3f636b3cbf4330b9U, 0x3f0d71593e8f98e8U, 0x3f8e728cbf099524U,
  0x3ed3a34ebf0aa7bbU, 0x3f8a72e23f70bd22U, 0x3f488bb4bef24fc6U, 0xbf11188abeb3eb51U,
  0xbdf21fe4be23af39U, 0xbe6ac9ab3e96909aU, 0xbdee4c533d3b15f4U, 0xbdef98b63eb55ae1U,
  0xbc3f0ade3ea489adU, 0xbe6bd925be4ac683U, 0xbe32e6533ea2625eU, 0x3e2a06233ddd00cdU,
  0x3e13c192U,
};


ai_handle g_ob_model_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_ob_model_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

