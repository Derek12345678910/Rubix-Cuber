const cube = document.querySelector('.cube');
let isDragging = false;
let startX, startY;
let rotateX = 30, rotateY = 45, rotateZ = 0; // Initial cube rotation values
let currentRotationX = rotateX, currentRotationY = rotateY, currentRotationZ = rotateZ;
let isFaceTurn = false; // Determines if a face is being turned
let rotatingFace = null; // Current rotating face

// Function to detect if a face is clicked
function getFaceUnderPointer(e) {
  const element = document.elementFromPoint(e.clientX, e.clientY);
  return element.closest('.face');
}

// Mouse down event to start cube or face rotation
document.addEventListener('mousedown', (e) => {
  isDragging = true;
  startX = e.clientX;
  startY = e.clientY;

  // Check if the click is on a face for face-turning
  rotatingFace = getFaceUnderPointer(e);
  isFaceTurn = rotatingFace ? true : false;
});

// Mouse move event to rotate the cube or a face
document.addEventListener('mousemove', (e) => {
  if (!isDragging) return;

  let deltaX = e.clientX - startX;
  let deltaY = e.clientY - startY;

  if (isFaceTurn && rotatingFace) {
    // Rotate a specific face (for this example, rotate the front face)
    if (rotatingFace.classList.contains('front')) {
      cube.style.transform = `rotateX(${rotateX}deg) rotateY(${rotateY}deg) rotateZ(${deltaX}deg)`;
    }
    // Add similar logic for other faces (back, top, bottom, left, right)
  } else {
    // Rotate the entire cube on all three axes
    rotateY += deltaX * 0.5;
    rotateX -= deltaY * 0.5;
    rotateZ += (deltaX + deltaY) * 0.2; // Optional: adding some Z rotation for 3D effect

    currentRotationX = rotateX;
    currentRotationY = rotateY;
    currentRotationZ = rotateZ;

    // Apply the 3D rotation to the cube
    cube.style.transform = `rotateX(${rotateX}deg) rotateY(${rotateY}deg) rotateZ(${rotateZ}deg)`;

    startX = e.clientX;
    startY = e.clientY;
  }
});

// Mouse up event to stop dragging
document.addEventListener('mouseup', () => {
  isDragging = false;
  rotatingFace = null;
  isFaceTurn = false;
});

// Optional: Touch events for mobile devices
document.addEventListener('touchstart', (e) => {
  isDragging = true;
  startX = e.touches[0].clientX;
  startY = e.touches[0].clientY;
  rotatingFace = getFaceUnderPointer(e.touches[0]);
  isFaceTurn = rotatingFace ? true : false;
});

document.addEventListener('touchmove', (e) => {
  if (!isDragging) return;

  let deltaX = e.touches[0].clientX - startX;
  let deltaY = e.touches[0].clientY - startY;

  if (isFaceTurn && rotatingFace) {
    if (rotatingFace.classList.contains('front')) {
      cube.style.transform = `rotateX(${rotateX}deg) rotateY(${rotateY}deg) rotateZ(${deltaX}deg)`;
    }
  } else {
    rotateY += deltaX * 0.3;
    rotateX -= deltaY * 0.3;
    rotateZ += (deltaX + deltaY) * 0.1; // Adding Z rotation for 3D effect

    currentRotationX = rotateX;
    currentRotationY = rotateY;
    currentRotationZ = rotateZ;

    cube.style.transform = `rotateX(${rotateX}deg) rotateY(${rotateY}deg) rotateZ(${rotateZ}deg)`;

    startX = e.touches[0].clientX;
    startY = e.touches[0].clientY;
  }
});


document.addEventListener('touchend', () => {
  isDragging = false;
  rotatingFace = null;
  isFaceTurn = false;
});