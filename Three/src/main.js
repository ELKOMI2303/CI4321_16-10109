import * as THREE from 'three';

//1- Create a Scene
const scene = new THREE.Scene();

//2- Create a Camera Ortographic
const camera = new THREE.OrthographicCamera(-4, 4, 3, -3, 0.1, 10);
camera.position.z = 1;

//3- Create a Renderer
const renderer = new THREE.WebGLRenderer();
renderer.setSize(800, 600); 
document.body.appendChild(renderer.domElement);
renderer.setClearColor(0x1b1e2b); // backGround 0x1b1e2b

//4- Create a Vertex Triangle
const geometry = new THREE.BufferGeometry();
const vertices = new Float32Array([
    -1, -1, 0,   
     1, -1, 0,   
     0,  1, 0    
]);
geometry.setAttribute('position', new THREE.BufferAttribute(vertices, 3));

// Color vertex in RGB 
const colors = new Float32Array([
    0.0, 1.0, 0.0,  
    0.0, 0.0, 1.0,  
    1.0, 0.0, 0.0, 
   
]);
geometry.setAttribute('color', new THREE.BufferAttribute(colors, 3));


//5- Create Triangle
const material = new THREE.MeshBasicMaterial({ vertexColors: true });


const triangle = new THREE.Mesh(geometry, material);
scene.add(triangle);

//6- Redenrer the Triangle
function render() {
    renderer.render(scene, camera);
}

render();

// Evento to change camera aspect
window.addEventListener('resize', () => {
    camera.left = -800 / 300;  
    camera.right = 800 / 300;
    camera.top = 600 / 300;
    camera.bottom = -600 / 300;
    camera.updateProjectionMatrix();
    renderer.setSize(800, 600);
});