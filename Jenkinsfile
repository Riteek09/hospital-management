pipeline {
    agent any

    environment {
        // DockerHub registry credentials stored in Jenkins
        DOCKER_CREDENTIALS = 'dockerhub-credentials'
        IMAGE_NAME = 'ritik1108/hospital_cli_app'  // Use your Docker Hub username here
        IMAGE_TAG = 'latest'
    }

    stages {
        stage('Clone Repository') {
            steps {
                git branch: 'main', url: 'https://github.com/Riteek09/hospital-management'
            }
        }

        stage('Build Docker Image') {
            steps {
                script {
                    // Build Docker image
                    dockerImage = docker.build("${IMAGE_NAME}:${IMAGE_TAG}")
                }
            }
        }

        stage('Push Docker Image') {
            steps {
                script {
                    // Log in to DockerHub and push the image
                    docker.withRegistry('https://index.docker.io/v1/', DOCKER_CREDENTIALS) {
                        dockerImage.push("${IMAGE_TAG}")
                    }
                }
            }
        }

        stage('Deploy (Optional)') {
            when {
                branch 'main' // Only deploy if it's the main branch
            }
            steps {
                echo "Deploying the image to the production server..."
                // Example:
                // sh 'ssh user@server "docker pull ritik1108/hospital_cli_app:latest && docker run ..."'
            }
        }
    }

    post {
        always {
            cleanWs()  // Clean workspace after each run
        }
    }
}
