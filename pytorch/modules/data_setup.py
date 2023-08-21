import os
from torchvision import datasets, transforms
from torch.utils.data import DataLoader

NUM_WORKERS = os.cpu_count()


def create_dataloaders(
        training_dir: str,
        test_dir: str,
        transform: transforms.Compose,
        batch_size: int,
        num_workers: int=NUM_WORKERS,
):
    training_data = datasets.ImageFolder(training_dir, transform=transform)
    test_data = datasets.ImageFolder(test_dir, transform=transform)

    class_names = training_data.classes

    training_dataloader = DataLoader(
        training_data,
        batch_size=batch_size,
        shuffle=True,
        num_workers=num_workers,
        pin_memory=True,
    )

    test_dataloader = DataLoader(
        test_data,
        batch_size=batch_size,
        shuffle=True,
        num_workers=num_workers,
        pin_memory=True
    )

    return training_dataloader, test_dataloader, class_names

