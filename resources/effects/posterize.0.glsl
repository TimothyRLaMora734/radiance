// Reduce number of colors

void main(void) {
    gl_FragColor = texture2D(iFrame, uv);

    //float bins = 256. * pow(2, -8. * iIntensity);
    float bins = min(256., 1. / iIntensity);

    gl_FragColor = round(gl_FragColor * bins) / bins;
}
