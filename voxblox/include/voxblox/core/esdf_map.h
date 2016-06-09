#ifndef VOXBLOX_CORE_ESDF_MAP_H_
#define VOXBLOX_CORE_ESDF_MAP_H_

#include <glog/logging.h>
#include <memory>
#include <utility>

#include "voxblox/core/common.h"
#include "voxblox/core/layer.h"
#include "voxblox/core/voxel.h"

namespace voxblox {

class EsdfMap {
 public:
  typedef std::shared_ptr<TsdfMap> Ptr;

  struct Config {
    float esdf_voxel_size = 0.2;
    float esdf_voxels_per_side = 16;
  };

  explicit EsdfMap(Config config)
      : esdf_layer_(new Layer<EsdfVoxel>(config.esdf_voxel_size,
                                         config.esdf_voxels_per_side)) {
    block_size_ = config.esdf_voxel_size * config.esdf_voxels_per_side;
  }

  virtual ~EsdfMap() {}

  Layer<EsdfVoxel>* getEsdfLayerPtr() { return esdf_layer_.get(); }
  const Layer<EsdfVoxel>& getEsdfLayer() const { return *esdf_layer_; }

  FloatingPoint block_size() const { return block_size_; }

 protected:
  FloatingPoint block_size_;

  // The layers.
  Layer<EsdfVoxel>::Ptr esdf_layer_;
};

}  // namespace voxblox

#endif  // VOXBLOX_CORE_ESDF_MAP_H_
