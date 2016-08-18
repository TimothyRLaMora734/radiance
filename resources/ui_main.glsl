const vec2 PAT_SIZE = vec2(45., 75.);

float sdCapsule( vec2 p, vec2 a, vec2 b, float r )
{
    vec2 pa = p - a, ba = b - a;
    float h = clamp( dot(pa,ba)/dot(ba,ba), 0.0, 1.0 );
    return length( pa - ba*h ) - r;
}

void glow(vec2 p, inout vec4 color) {
    vec2 LEN = vec2(300., 0.);
    float FRINGE = 75.;
    color = composite(color, vec4(0., 0.5, 1., 0.5 * max(0., 1. - sdCapsule((v_uv*v_size).xy, p - LEN, p + LEN, FRINGE) / FRINGE)));
}

void main(void) {
    f_color0 = vec4(0.);
    vec2 frag = v_uv * v_size;
    if(iSelection) {
        f_color0 = vec4(0., 0., 0., 1.);
        for(int i=0; i < 8; i++) {
            ivec3 c;
            c = ivec3(1, i, 0);
            vec2 p = vec2(175. + (i + 2 * int(i >= 4)) * 175., 420.);
            f_color0 = composite(f_color0, vec4(dataColor(c), rounded_rect_df(frag,p, PAT_SIZE, RADIUS) <= 1.));
            p = vec2(175. + (i + 2 * int(i >= 4)) * 175., 180.);
            c.y += 8;
            f_color0 = composite(f_color0, vec4(dataColor(c), rounded_rect_df(frag,p, PAT_SIZE, RADIUS) <= 1.));
        }
        f_color0 = composite(f_color0, vec4(dataColor(ivec3(3, 0, 0)), rounded_rect_df(frag,vec2(975., 300.), PAT_SIZE, RADIUS) <= 1.));
    } else {
        float g = v_uv.y * 0.1 + 0.2;
        f_color0 = vec4(g, g, g, 1.);

        glow(vec2(475., iLeftDeckSelector == 0 ? 420. : 180.),f_color0);
        glow(vec2(1475., iRightDeckSelector == 1 ? 420. : 180.),f_color0);

        for(int i=0; i < 8; i++) {
            vec2 p;
            p = vec2(175. + (i + 2 * int(i >= 4)) * 175., 420.);
            f_color0 = composite(f_color0, fancy_rect(frag,p, PAT_SIZE, iSelected == i + 1));
            p = vec2(175. + (i + 2 * int(i >= 4)) * 175., 180.);
            f_color0 = composite(f_color0, fancy_rect(frag,p, PAT_SIZE, iSelected == i + 9));
        }
        f_color0 = composite(f_color0, fancy_rect(frag,vec2(962.5, 300.), vec2(130., 200.), iSelected == 17 || iSelected == 18));
    }
}
