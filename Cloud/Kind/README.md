To create a single node podman Kind cluster use
KIND_EXPERIMENTAL_PROVIDER=podman kind create cluster --config=SingleNodeCluster.yaml --name single-cluster

kind get clusters
kind delete clusters single-cluster
