- [Kubernetes Tutorials](https://redhat-scholars.github.io/kubernetes-tutorial/kubernetes-tutorial/index.html)
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


## Create and set namespace 

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


## Create pods
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
  
- Login to pod
  ```bash
  kubectl exec --stdin --tty <pod-name> -- /bin/bash
  ```

## ReplicaSets
It is controller of pods. We should not directly create this object.

- Create Replicaset. This will create Pods according to file definition and will manage these pods. Like automatic restart and all.
  ```bash
  kubectl create -f 3-replica-set.yaml
  ```
  
- View replicaset
  ```bash
  kubectl get replicaset -n <namespace>
  kubectl get pods -n <namespace>
  ```
  
- Delete replicaset. This will first delete underlying pods then rs object itself.
  ```bash
  kubectl delete replicaset <rs-name> -n <namespace>
  ```

## Deployments
It manages replica-set and this should be the object created by users. It is superset of replicaset with additional functionality of rolling update.
- Create deployment. This will create repplicset according to file definition and will manage these pods. Like automatic restart and all.
  ```bash
  kubectl create -f 4-deployment.yaml
  ```
  
- View deployment
  ```bash
  kubectl get deployment -n <namespace>
  kubectl get replicasets -n <namespace>
  kubectl get pods -n <namespace>
  ```
  
- Delete deployment. This will first delete underlying pods then rs object itself.
  ```bash
  kubectl delete deployment <deployment> -n <namespace>
  ```
  
- To change scaling -
  ```bash
  kubectl scale --replicas=3 deployment/<deployment-name> -n <namespace>
  ```

- Changing image ( rolling update )
  ```bash
  kubectl set image deployment/<deployment-name> name=gob/echo-server:v2
  ```
## Services
A service can be defined as a logical set of pods. It can be defined as an abstraction on the top of the pod which provides a single IP address and DNS name by which pods can be accessed. With Service, it is very easy to manage load balancing configuration. It helps pods to scale very easily.

A service is a REST object in Kubernetes whose definition can be posted to Kubernetes apiServer on the Kubernetes master to create a new instance.

- Create NodePort Service
  ```bash
  kubectl create -f 5-service.yaml
  ```

- View Service
  ```bash
  kubectl get services <service-name> -n <namespace> -o wide
  kubectl decribe services <service-name> -n <namespace>
  ```
  
## Logging
```bash
kubectl get pods
kubectl logs <pod-name>

// Last failed pod logs
kubectl logs <pod-name> -p 

// Grabs log of all app with selector
kubectl logs -l app=<app-selector>
```

## Labels
Labels are key value pairs and used extensively in Kubernetes as a selector of elements/objects.

- To add a label to Pod
  ```
  kubectl label pod -l app=<app-name> <key=value>
  ```

- Remove label
  ```
  kubectl label pod -l app<app-name> <key>-
  ```

## Configs - 
This object is used by pods to read configs like env variables. During change of configs, old pod will terminate and new POD will be recreated.

  ### env variables
  - Add/Change env variables
    ```bash
    kubectl set env deployment <deployment-name> NAME="VALUE"
    ```
  - Delete ENV variables
    ```bash
    kubectl set env deployment <deployment-name> NAME-
    ```

  ### Config Maps
  config maps are similar to configs - env but created using file
  ```bash
  kubectl create  cm my-config --from-env-file=sample.properties
  ```

  ### Secrets
  Similar to config maps, secrets are also config but it is base64 encoded
  ```bash
  kubectl create secret generic my-secret --from-literal=user='MyUserName' --from-literal=password='MyPassword'
  ```
  You can easily decode base64 encoded message using -
  ```bash
  echo 'encoded-text' | base64 --decode
  ```


## Service Discovery
All services created in Kubernetes have its entry in DNS and can be accessed via its dns name -
```bash
<service-name>.<namespace>.svc.cluster.local:<port>
```

If you are in same namespace you can directly use- `<service-name>:<port>`

## Liveness and Readiness Probe
Using these two probes, Kubernetes provides/manages high availabilty

- **Liveness :** Whether my pod is alive.
- **Readiness:**  Are you ready to accept new requests, Are you ready for LoadBalancer.
  Liveness probe runs before readiness probe.
  R u alive ? R u ready ?

# Deployment Strategies -

## Blue Green Deployment
    - Gen is running
Blue is new version of same application but having different app name label
Single service is service Green one.
To switch to Blue one, simply patch the running service -
`kubectl patch svc/<svc-name> -p '{"spec":{"selector":{"app": "new app name
label"}}}'`
