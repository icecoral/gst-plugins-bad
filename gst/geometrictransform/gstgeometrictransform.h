/* GStreamer
 * Copyright (C) <2010> Thiago Santos <thiago.sousa.santos@collabora.co.uk>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __GST_GEOMETRIC_TRANSFORM_H__
#define __GST_GEOMETRIC_TRANSFORM_H__

#include <gst/video/gstvideofilter.h>
#include <gst/video/video.h>

G_BEGIN_DECLS

#define GST_TYPE_GEOMETRIC_TRANSFORM \
  (gst_geometric_transform_get_type())
#define GST_GEOMETRIC_TRANSFORM(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_GEOMETRIC_TRANSFORM,GstGeometricTransform))
#define GST_GEOMETRIC_TRANSFORM_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_GEOMETRIC_TRANSFORM,GstGeometricTransformClass))
#define GST_IS_GEOMETRIC_TRANSFORM(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_GEOMETRIC_TRANSFORM))
#define GST_IS_GEOMETRIC_TRANSFORM_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_GEOMETRIC_TRANSFORM))
#define GST_GEOMETRIC_TRANSFORM_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS((obj),GST_TYPE_GEOMETRIC_TRANSFORM,GstGeometricTransformClass))

typedef struct _GstGeometricTransform GstGeometricTransform;
typedef struct _GstGeometricTransformClass GstGeometricTransformClass;

typedef gboolean (*GstGeometricTransformMapFunc) (GstGeometricTransform * gt,
    gint x, gint y, gdouble * _out_x, gdouble *_out_y);

/**
 * GstGeometricTransform:
 *
 * Opaque datastructure.
 */
struct _GstGeometricTransform {
  GstVideoFilter videofilter;

  gint width, height;
  GstVideoFormat format;
};

struct _GstGeometricTransformClass {
  GstVideoFilterClass parent_class;

  GstGeometricTransformMapFunc map_func;
};

GType gst_geometric_transform_get_type (void);

G_END_DECLS

#endif /* __GST_GEOMETRIC_TRANSFORM_H__ */
