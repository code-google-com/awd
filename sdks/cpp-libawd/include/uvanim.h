#ifndef _LIBAWD_UVANIM_H
#define _LIBAWD_UVANIM_H

#include "attr.h"
#include "name.h"
#include "block.h"


typedef struct _AWD_uvanim_fr {
    awd_float64 *transform_mtx;
    struct _AWD_uvanim_fr *next;
} AWD_uvanim_fr;


class AWDUVAnimation : public AWDNamedElement, 
    public AWDAttrElement, public AWDBlock
{
    private:
        awd_uint16 num_frames;

        AWD_uvanim_fr *first_frame;
        AWD_uvanim_fr *last_frame;

    protected:
        awd_uint32 calc_body_length(bool,bool);
        void write_body(int, bool,bool);

    public:
        AWDUVAnimation(const char *, awd_uint16);
        ~AWDUVAnimation();

        void set_next_frame_tf(awd_float64 *);
};

#endif
