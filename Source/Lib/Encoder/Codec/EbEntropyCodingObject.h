/*
* Copyright(c) 2019 Intel Corporation
* SPDX - License - Identifier: BSD - 2 - Clause - Patent
*/

#ifndef EbEntropyCodingObject_h
#define EbEntropyCodingObject_h

#include "EbDefinitions.h"
#include "EbCabacContextModel.h"
#include "EbBitstreamUnit.h"
#include "EbObject.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct Bitstream {
    EbDctor dctor;
    EbPtr   output_bitstream_ptr;
} Bitstream;

typedef struct EntropyCoder {
    EbDctor        dctor;
    FRAME_CONTEXT *fc; /* this frame entropy */
    AomWriter      ec_writer;
    EbPtr          ec_output_bitstream_ptr;
    uint64_t       ec_frame_size;
} EntropyCoder;

typedef struct EntropyTileInfo
{
    EbDctor           dctor;
    EntropyCoder     *entropy_coder_ptr;
    int8_t            entropy_coding_current_available_row;
    EbBool            entropy_coding_row_array[MAX_SB_ROWS];
    int8_t            entropy_coding_current_row;
    int8_t            entropy_coding_row_count;
    EbHandle          entropy_coding_mutex;
    EbBool            entropy_coding_in_progress;
    EbBool            entropy_coding_tile_done;
} EntropyTileInfo;

extern EbErrorType entropy_tile_info_ctor(
        EntropyTileInfo *entropy_tile_info_ptr,
        uint32_t buf_size);

extern EbErrorType bitstream_ctor(Bitstream *bitstream_ptr, uint32_t buffer_size);

extern EbErrorType entropy_coder_ctor(EntropyCoder *entropy_coder_ptr, uint32_t buffer_size);
#ifdef __cplusplus
}
#endif
#endif // EbEntropyCodingObject_h
