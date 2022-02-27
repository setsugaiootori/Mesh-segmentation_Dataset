#ifndef TRIMESH_ALGO_H
#define TRIMESH_ALGO_H
/*
Szymon Rusinkiewicz
Princeton University

TriMesh_algo.h
Various mesh-munging algorithms using TriMeshes
*/


#include "Vec.h"
#include "XForm.h"
#include "TriMesh.h"


// Optimally re-triangulate a mesh by doing edge flips
extern void edgeflip(TriMesh *mesh);

// Flip the order of vertices in each face.  Turns the mesh inside out.
extern void faceflip(TriMesh *mesh);

// One iteration of umbrella-operator smoothing
extern void umbrella(TriMesh *mesh, float stepsize);

// Taubin lambda/mu mesh smoothing
extern void lmsmooth(TriMesh *mesh, int niters);

// Remove the indicated vertices from the TriMesh.
extern void remove_vertices(TriMesh *mesh, const std::vector<bool> &toremove);

// Remove vertices that aren't referenced by any face
extern void remove_unused_vertices(TriMesh *mesh);

// Remove faces as indicated by toremove.  Should probably be
// followed by a call to remove_unused_vertices()
extern void remove_faces(TriMesh *mesh, const std::vector<bool> &toremove);

// Remove long, skinny faces.  Should probably be followed by a
// call to remove_unused_vertices()
extern void remove_sliver_faces(TriMesh *mesh);

// Remap vertices according to the given table
extern void remap_verts(TriMesh *mesh, const std::vector<int> &remap_table);

// Reorder vertices in a mesh according to the order in which
// they are referenced by the tstrips or faces.
extern void reorder_verts(TriMesh *mesh);

// Perform one iteration of subdivision on a mesh.
enum { SUBDIV_PLANAR, SUBDIV_LOOP, SUBDIV_LOOP_ORIG, SUBDIV_LOOP_NEW,
       SUBDIV_BUTTERFLY, SUBDIV_BUTTERFLY_MODIFIED };
extern void subdiv(TriMesh *mesh, int scheme = SUBDIV_LOOP);

// Smooth the mesh geometry
extern void smooth_mesh(TriMesh *themesh, float sigma);

// Bilateral smoothing
extern void bilateral_smooth_mesh(TriMesh *themesh, float sigma1, float sigma2);

// Diffuse the normals across the mesh
extern void diffuse_normals(TriMesh *themesh, float sigma);

// Diffuse the curvatures across the mesh
extern void diffuse_curv(TriMesh *themesh, float sigma);

// Diffuse the curvature derivatives across the mesh
extern void diffuse_dcurv(TriMesh *themesh, float sigma);

// Given a curvature tensor, find principal directions and curvatures
extern void diagonalize_curv(const vec &old_u, const vec &old_v,
			     float ku, float kuv, float kv,
			     const vec &new_norm,
			     vec &pdir1, vec &pdir2, float &k1, float &k2);

// Reproject a curvature tensor from the basis spanned by old_u and old_v
// (which are assumed to be unit-length and perpendicular) to the
// new_u, new_v basis.
extern void proj_curv(const vec &old_u, const vec &old_v,
		      float old_ku, float old_kuv, float old_kv,
		      const vec &new_u, const vec &new_v,
		      float &new_ku, float &new_kuv, float &new_kv);

// Like the above, but for dcurv
extern void proj_dcurv(const vec &old_u, const vec &old_v,
		       const Vec<4> old_dcurv,
		       const vec &new_u, const vec &new_v,
		       Vec<4> &new_dcurv);

// Create an offset surface from a mesh
extern void inflate(TriMesh *mesh, float amount);

// Transform the mesh by the given matrix
extern void apply_xform(TriMesh *mesh, const xform &xf);

// Translate the mesh
extern void trans(TriMesh *mesh, const vec &transvec);

// Rotate the mesh by r radians
extern void rot(TriMesh *mesh, float r, const vec &axis);

// Scale the mesh - isotropic
extern void scale(TriMesh *mesh, float s);

// Scale the mesh - anisotropic in X, Y, Z
extern void scale(TriMesh *mesh, float sx, float sy, float sz);

// Scale the mesh - anisotropic in an arbitrary direction
extern void scale(TriMesh *mesh, float s, const vec &d);

// Clip mesh to the given bounding box 
extern void clip(TriMesh *mesh, const TriMesh::BBox &b);

// Find center of mass of a bunch of points 
extern point point_center_of_mass(const vector<point> &pts);

// Find (area-weighted) center of mass of a mesh 
extern point mesh_center_of_mass(TriMesh *mesh);

// Compute covariance of a bunch of points 
extern void point_covariance(const vector<point> &pts, float C[3][3]);

// Compute covariance of faces (area-weighted) in a mesh 
extern void mesh_covariance(TriMesh *mesh, float C[3][3]);

// Scale the mesh so that mean squared distance from center of mass is 1 
extern void normalize_variance(TriMesh *mesh);

// Rotate model so that first principal axis is along +X (using 
// forward weighting), and the second is along +Y 
extern void pca_rotate(TriMesh *mesh);

// As above, but only rotate by 90/180/etc. degrees w.r.t. original 
extern void pca_snap(TriMesh *mesh);

// Flip faces so that orientation among touching faces is consistent 
extern void orient(TriMesh *mesh);

// Remove boundary vertices (and faces that touch them) 
extern void erode(TriMesh *mesh);

// Add a bit of noise to the mesh 
extern void noisify(TriMesh *mesh, float amount);


///////////// for my project /////////////////
extern void colorbycurv(TriMesh *mesh, const char *scale, const char *smooth);

#endif
