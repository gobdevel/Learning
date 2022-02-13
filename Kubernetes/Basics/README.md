- [Kubernetes Tutorials](https://redhat-scholars.github.io/kubernetes-tutorial/kubernetes-tutorial/pod-rs-deployment.html)
- [Kind Quick Start](https://kind.sigs.k8s.io/docs/user/quick-start/)
- [Reference Repo](https://github.com/redhat-scholars/kubernetes-tutorial)

# Installation
    Install Docker for your OS
    Install Kubernetes (kubectl)
    Install Kind (for local cluster setup)

# Cluster Setup
- Create Cluster using below command
`kind create cluster --name local-cluster`

- Get Cluster info
`kind get clusters`

- Delete  cluster
`kind delete clusters <cluster-name>`

- If you are working on multiple cluster set working cluster using below -
  ```bash
  kubectl cluster-info --context kind-local-cluster
  ```

- Load your private/local docker images to kind cluster. This can be used locally in Kubernetes cluster.\ 
  ```bash
  kind load docker-image echo-server:v1  --name local-cluster
  ```

#### To create a multi-node cluster -
```kind-multinode-config.yaml
apiVersion: kind.x-k8s.io/v1alpha4
kind: Cluster
nodes:
  - role: constrol-plane
  - role: worker
  - role: worker
```

- Create Kind Cluster 
  ```bash
  kind create cluster --config <file> --name <name>
  ```

# Different types of Resources in Kubernetes
- Namespaces
- Pods
- Replica-set
- Deployments
- Servcices
- Persistent-volume
- Persistent-volume-claim
- Labels
- Secrets
- nodes
- cluster

# CLI to  -
kubectl create deployment my-app --image=gobdev/kube-learn:v1
kubectl get events --sort-by=.metadata.creationTimestamp
kubectl expose deployment my-app --port=8080 --type=LoadBalancer

kubectl config set-context --current --namespace=my-namespace


# Create and set namespace 

1. Create name space
   ```bash
   kubectl create namespace <namespace>
   ```
2. Get namespaces
   ```bash
   kubectl get namespaces
   ```

3. Set namespace to default context so that you dont have to type everytime
   ```bash
   kubectl config set-context --current --namespace=<namespace>
   ```

4. Deleting a namespace will delete all its resources (pods, services, pv, pvc etc)
   ```bash
   kubectl delete namespace <namespace>
   ```


# Create pods
Pod is a smallest unit in Kubernetes, you can create a pod with a container inside using 2-pod.yaml.

- Create pod command line
  ```bash
  kubectl run my-pod --image=gob/echo-server:v1
  kubectl create -f <file-name>
  ```

- Check Pod
  ```bash
  kubectl get pods -n <namespace>
  kubectl describe pod <podname> -n <namespace>
  ```
 
- Remove Pod
  ```bash
  kubectl delete pods <podname> -n <namespace>
  ```

### ReplicaSets
It is controller of pods.

### deployments
It manages replica-set

### Scaling
kubectl scale --replicas=3 deployment/<deployment-name>

### Chaning image ( rolling update )
kubectl set image deployment/<deployment-name> name=gob/echo-server:v2 


#### Logging
kubectl get pods
kubectl logs <pod>
kubectl logs <pod> -p // Last failed pod logs
kubectl logs -l app=<app-selector> // Grabs log of all app with selector

#### Labels
Labels are key value pairs and used extensively in Kubernetes as a selector of
elements/objects.

# To add a label to Pod
`kubectl label pod -l app=<app-name> <key=value>`

# Remove label
`kubectl label pod -l app<app-name> <key>-`

#### Configs

During change of env variable, old pod will terminate and new POD will be re
created
Add/Change env variables
kubectl set env deployment <deployment-name> NAME="VALUE"

Delete ENV variables
kubectl set env deployment <deployment-name> NAME-

#### Config Maps
kubectl create  cm my-config --from-env-file=sample.properties


#### Secrets
Similar to config maps, secrets are also config but it is base64 encoded.
kubectl create secret generic my-secret --from-literal=user='MyUserName'
--from-literal=password='MyPassword'

You can easily decode base64 encoded message using -
echo 'encoded-text' | base64 --decode


##### SERVICE DISCOVERY
All services created in Kubernetes have its entry in DNS
<service-name>.<namespace>.svc.cluster.local:<port>

If you are in same namespace you can directly use-
<service-name>:<port>

#### Liveness and Readiness
Liveness probe runs before readiness probe.
R u alive ? R u ready ?

Liveness : Are you alive
Readiness : Are you ready to accept new requests, Are you ready for
LoadBalancer.

#### DEPLOYMENT STARTEGY => BLUE-GREEN Deployment
Green is running
Blue is new version of same application but having different app name label
Single service is service Green one.
To switch to Blue one, simply patch the running service -
`kubectl patch svc/<svc-name> -p '{"spec":{"selector":{"app": "new app name
label"}}}'`
