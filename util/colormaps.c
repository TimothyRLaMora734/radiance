#include "util/color.h"

struct colormap cm_rainbow = {
    .name = "Rainbow",
    .n_points = 6,
    .points = {
        { .x = 0.,
          .y = {1., 0., 0., 1.},
          .gamma = 1.,
        },
        { .x = .2,
          .y = {1., 1., 0., 1.},
          .gamma = 1.,
        },
        { .x = .4,
          .y = {0., 1., 0., 1.},
          .gamma = 1.,
        },
        { .x = .6,
          .y = {0., 1., 1., 1.},
          .gamma = 1.,
        },
        { .x = .8,
          .y = {0., 0., 1., 1.},
          .gamma = 1.,
        },
        { .x = 1.,
          .y = {1., 0., 1., 1.},
          .gamma = 1.,
        },
    },
};

struct colormap cm_rainbow_edged = {
    .name = "Rainbow Edged",
    .n_points = 8,
    .points = {
        { .x = 0.0,
          .y = {0., 0., 0., 1.},
          .gamma = 1.,
        },
        { .x = 0.05,
          .y = {1., 0., 0., 1.},
          .gamma = 1.,
        },
        { .x = .2,
          .y = {1., 1., 0., 1.},
          .gamma = 1.,
        },
        { .x = .4,
          .y = {0., 1., 0., 1.},
          .gamma = 1.,
        },
        { .x = .6,
          .y = {0., 1., 1., 1.},
          .gamma = 1.,
        },
        { .x = .8,
          .y = {0., 0., 1., 1.},
          .gamma = 1.,
        },
        { .x = 0.95,
          .y = {1., 0., 1., 1.},
          .gamma = 1.,
        },
        { .x = 1.0,
          .y = {1., 1., 1., 1.},
          .gamma = 1.,
        },
    },
};

struct colormap cm_rainbow_equal = {
    .name = "Rainbow Equal",
    .n_points = 6,
    .points = {
        { .x = 0.,
          .y = {1., 0., 0., 1.},
          .gamma = 1.,
        },
        { .x = .2,
          .y = {0.5, 0.5, 0., 1.},
          .gamma = 1.,
        },
        { .x = .4,
          .y = {0., 1., 0., 1.},
          .gamma = 1.,
        },
        { .x = .6,
          .y = {0., 0.5, 0.5, 1.},
          .gamma = 1.,
        },
        { .x = .8,
          .y = {0., 0., 1., 1.},
          .gamma = 1.,
        },
        { .x = 1.,
          .y = {0.5, 0., 0.5, 1.},
          .gamma = 1.,
        },
    },
};

struct colormap cm_jet = {
    .name = "Jet",
    .n_points = 6,
    .points = {
        { .x = 0.00,
          .y = {0.5, 0.0, 0.0, 1.},
          .gamma = 1.,
        },
        { .x = 0.10,
          .y = {1.0, 0.0, 0.0, 1.},
          .gamma = 1.,
        },
        { .x = 0.35,
          .y = {1.0, 1.0, 0.0, 1.},
          .gamma = 1.,
        },
        { .x = 0.64,
          .y = {0.0, 1.0, 1.0, 1.},
          .gamma = 1.,
        },
        { .x = 0.89,
          .y = {0.0, 0.0, 1.0, 1.},
          .gamma = 1.,
        },
        { .x = 1.00,
          .y = {0.0, 0.0, 0.5, 1.},
          .gamma = 1.,
        },
    },
};

